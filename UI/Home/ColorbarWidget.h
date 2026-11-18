#pragma once

#include "Common/Structures/ColormapPresets.h"
#include "qcustomplot.h"
#include <QColor>
#include <QString>
#include <QUuid>
#include <QVector>
#include <QWidget>

namespace GViS {
namespace Visualize {
namespace Layers {
class LayerSettings;
}
} // namespace Visualize
} // namespace GViS

class ColorBarWidget : public QWidget {
    Q_OBJECT

  public:
    explicit ColorBarWidget(QWidget* parent = nullptr);
    ~ColorBarWidget() override;

    // Задать цветовую палитру (градиент) для отображения
    void setColorMap(const GViS::Visualize::ColorMap& colorMap);

    // Применить настройки слоя (диапазон значений, палитра, видимость и т.д.)
    void setSettings(GViS::Visualize::Layers::LayerSettings* settings);

    // Переключение режима: true — вертикальный, false — горизонтальный
    void setOrientation(bool isVertical);

    // Доступ к нижележащему QCustomPlot
    QCustomPlot* plot() const {
        return m_plot;
    }

  private:
    void setupPlot();
    void styleActiveAxis();
    void applyGradient(const GViS::Visualize::ColorMap& colorMap);

  private slots:
    void handleUpdateValues();

  private:
    QCustomPlot*   m_plot       = nullptr;
    QCPColorScale* m_colorScale = nullptr;
    bool           m_isVertical = false;

    GViS::Visualize::ColorMap               m_currentColorMap;
    GViS::Visualize::Layers::LayerSettings* m_settings = nullptr;
};