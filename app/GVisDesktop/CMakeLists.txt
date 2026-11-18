# 1. Настройка переводов
#------------------------------------------
set(TS_FILES
    ${PROJECT_SOURCE_DIR}/app/translates/GViS_ru.ts
)
#добавление файлов перевода
qt6_add_translations(
    GViS
    TS_FILES ${TS_FILES}
RESOURCE_PREFIX "/i18n"
)

#создание исполнимого qt файла
qt_add_executable(GViS
    MANUAL_FINALIZATION
    main.cpp
    ${PROJECT_SOURCE_DIR}/app/resources/icons.qrc
    ${PROJECT_SOURCE_DIR}/app/resources/styles.qrc
    ${PROJECT_SOURCE_DIR}/app/resources/shaders.qrc
    ${QM_FILES}
)

target_link_libraries(GViS PRIVATE
            project_config
            GViS::Common
            GViS::Core
            GViS::IO
            GViS::Visualize
            GViS::Models
            # Charting
            # Filtering
            # Physics
            # Remote
            # GViS::Session
            GViS::UI
            qcustomplot
            Qt6::Core
            Qt6::Widgets
            Qt6::Gui
            # Qt6::Quick
            # Qt6::Qml
            VTK::GUISupportQt
            VTK::CommonColor
            VTK::ImagingHybrid 
            VTK::RenderingVolumeOpenGL2
            VTK::RenderingOpenGL2
            VTK::InteractionStyle
            OpenMP::OpenMP_CXX
)
# Генерация макросов инициализации фабрик
vtk_module_autoinit(
    TARGETS GViS
    MODULES ${VTK_LIBRARIES}
)

if(WIN32) # на виндовс только gui
    set_target_properties(GViS PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
    target_sources(GViS PRIVATE ${PROJECT_SOURCE_DIR}/app/resources/app_icon.rc)
    get_filename_component(VTK_INSTALL_DIR "${VTK_DIR}/../../.." ABSOLUTE)
    set(VTK_BIN_DIR "${VTK_INSTALL_DIR}/bin")

    add_custom_command(TARGET GViS POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory 
    "${VTK_BIN_DIR}" 
    "$<TARGET_FILE_DIR:GViS>"
    COMMENT "Copying VTK binaries..."
    )
    add_custom_command(TARGET GViS POST_BUILD
    COMMAND ${QT_DIR}/bin/windeployqt.exe
    --compiler-runtime
        $<TARGET_FILE:GViS>
            COMMENT "Running windeployqt..."
            )

    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        get_filename_component(MINGW_BIN_DIR "${CMAKE_CXX_COMPILER}" DIRECTORY)
        get_filename_component(MINGW_ROOT_DIR "${MINGW_BIN_DIR}" DIRECTORY)
        file(GLOB MINGW_TARGET_LIB_DIRS "${MINGW_ROOT_DIR}/*-w64-mingw32/lib")
        find_file(GViS_OPENMP_RUNTIME_DLL
            NAMES libgomp-1.dll
            PATHS ${MINGW_TARGET_LIB_DIRS} "${MINGW_BIN_DIR}"
            NO_DEFAULT_PATH
            REQUIRED
        )

        add_custom_command(TARGET GViS POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${GViS_OPENMP_RUNTIME_DLL}"
                "$<TARGET_FILE_DIR:GViS>"
            COMMENT "Copying GNU OpenMP runtime..."
        )
        install(FILES "${GViS_OPENMP_RUNTIME_DLL}" DESTINATION ${CMAKE_INSTALL_BINDIR})
    endif()
endif()
        
include(GNUInstallDirs)
install(TARGETS GViS
BUNDLE DESTINATION .
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/" 
DESTINATION bin 
FILES_MATCHING 
PATTERN "*.dll"        # Забираем библиотеки
PATTERN "platforms/*"  # Забираем критический плагин qwindows.dll
PATTERN "styles/*"
PATTERN "imageformats/*"
)
qt_finalize_executable(GViS)