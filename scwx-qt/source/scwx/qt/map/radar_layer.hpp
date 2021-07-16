#include <qmapboxgl.hpp>

namespace scwx
{
namespace qt
{

class RadarLayerImpl;

class RadarLayer : public QMapbox::CustomLayerHostInterface
{
public:
   explicit RadarLayer();
   ~RadarLayer();

   RadarLayer(const RadarLayer&) = delete;
   RadarLayer& operator=(const RadarLayer&) = delete;

   RadarLayer(RadarLayer&&) noexcept;
   RadarLayer& operator=(RadarLayer&&) noexcept;

   void initialize() override final;
   void render(const QMapbox::CustomLayerRenderParameters&) override final;
   void deinitialize() override final;

private:
   std::unique_ptr<RadarLayerImpl> p;
};

} // namespace qt
} // namespace scwx
