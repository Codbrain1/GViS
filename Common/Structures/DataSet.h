#include <QHash>
#include <QString>
#include <array>
#include <span>
#include <variant>
#include <vector>

namespace GViS::IO {
class ParticleData {
  public:
    /**
     * возвращает массив значений по которым будут раскрашены частицы
     */
    void* getColorByField(const QString& field);

    /**
     * задает массив значений которому будут расскрашены частицы
     */
    void setColorByField(const QString& field);


  private:
    /**
     *координаты частиц в хранятся в формате xyz,xyz,...
     */
    using Vec3f = std::variant<std::array<float, 3>>;  // AoS float structure,
    using Vec3d = std::variant<std::array<double, 3>>; // AoS double structure,
    using Vec2f = std::variant<std::array<float, 2>>;
    using Vec2d = std::variant<std::array<double, 2>>;

    /*
     * координаты частиц хранятся в формате xxx..., yyy...,zzz...
     */
    template <typename T> struct SoAPositions2D {
        std::vector<T> x;
        std::vector<T> y;
    };

    template <typename T> struct SoAPositions3D {
        std::vector<T> x;
        std::vector<T> y;
        std::vector<T> z;
    };

    /*
     * хранит позиции частиц, в для различных сочетаний типов
     */
    using PositionsVariant = std::variant<std::vector<Vec2d>,
                                          std::vector<Vec2f>,
                                          std::vector<Vec3d>,
                                          std::vector<Vec3f>,
                                          SoAPositions2D<float>,
                                          SoAPositions2D<double>,
                                          SoAPositions3D<float>,
                                          SoAPositions3D<double>>;


    /*
     *хранит скалярные поля частиц
     */
    using FieldVariant = std::variant<std::vector<double>,
                                      std::vector<float>,
                                      std::vector<int>,
                                      std::vector<unsigned int>>;

    PositionsVariant             m_positions;
    QHash<QString, FieldVariant> m_fields;
};

class DataSet {
  public:
  private:
    ParticleData m_particleData;
};


} // namespace GViS::IO