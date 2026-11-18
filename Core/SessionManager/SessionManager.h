#pragma once
#include "Core/LayerManager/LayerManager.h"
#include "Core/ObjectRegistry/ObjectRegistry.h"
#include "Core/ViewManager/ViewManager.h"
#include <QObject>
#include "Session/SessionStorage.h"
#include "Structures/SessionStructures.h"
#include <functional>
#include <memory>
#include <optional>

namespace GViS::Core {

class SessionManager : public QObject { // Исправлена опечатка в имени
    Q_OBJECT
  public:
    explicit SessionManager(GViS::Core::ObjectRegistry* registry,
                            GViS::Core::LayerManager*   layerManager,
                            GViS::Core::ViewManager*    viewManager,
                            QObject*                    parent = nullptr);
    // Сохранение и загрузка проекта
    bool saveProject(const QString& filePath, GViS::Session::ProjectFormat format);
    bool loadProject(const QString& filePath);
    void
    setVideoPlayerStateHandlers(std::function<Session::VideoPlayerDTO()>            saveState,
                                std::function<QList<QUuid>()>                       playerLayerIds,
                                std::function<void(const Session::VideoPlayerDTO&)> restoreState);

    // сохранение и загрузка палитр
    bool savePalette(const Visualize::ColorMap& map, const QString& filePath);
    std::optional<Visualize::ColorMap> loadPalette(const QString& filePath);

  signals:
    [[deprecated]]
    void projectLoaded(const GViS::Session::ProjectState& state);
    void errorOccurred(const QString& msg);

  private:
    GViS::Session::ProjectDTO                createProjectDTO() const;
    bool                                     fromProjectDTO(const GViS::Session::ProjectDTO& dto);
    GViS::Core::ObjectRegistry*              m_registry;
    GViS::Core::LayerManager*                m_layerManager;
    GViS::Core::ViewManager*                 m_viewManager;
    std::function<Session::VideoPlayerDTO()> m_saveVideoPlayerState;
    std::function<QList<QUuid>()>            m_playerLayerIds;
    std::function<void(const Session::VideoPlayerDTO&)> m_restoreVideoPlayerState;
    std::unique_ptr<GViS::Session::SessionStorage>      m_storage_session;
};
} // namespace GViS::Core