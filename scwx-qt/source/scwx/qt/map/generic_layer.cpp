#include <scwx/qt/map/generic_layer.hpp>

namespace scwx
{
namespace qt
{
namespace map
{

class GenericLayerImpl
{
public:
   explicit GenericLayerImpl(std::shared_ptr<MapContext> context) :
       context_ {context}
   {
   }

   ~GenericLayerImpl() {}

   std::shared_ptr<MapContext> context_;
};

GenericLayer::GenericLayer(std::shared_ptr<MapContext> context) :
    p(std::make_unique<GenericLayerImpl>(context))
{
}
GenericLayer::~GenericLayer() = default;

std::shared_ptr<MapContext> GenericLayer::context() const
{
   return p->context_;
}

} // namespace map
} // namespace qt
} // namespace scwx
