add_subdirectory(DataTreeModel)

add_library(Models INTERFACE)
add_library(GViS::Models ALIAS Models)
target_include_directories(Models INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(Models INTERFACE
            project_config
            GViS::Core
            DataTreeModel
            # SceneSettingsModel
            # SessionModel
            # TaskProgressModel
            Qt6::Core
)