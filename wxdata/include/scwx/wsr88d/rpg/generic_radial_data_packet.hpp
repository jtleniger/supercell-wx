#pragma once

#include <scwx/wsr88d/rpg/packet.hpp>

#include <cstdint>
#include <memory>

namespace scwx
{
namespace wsr88d
{
namespace rpg
{

class GenericRadialDataPacketImpl;

class GenericRadialDataPacket : public Packet
{
public:
   explicit GenericRadialDataPacket();
   ~GenericRadialDataPacket();

   GenericRadialDataPacket(const GenericRadialDataPacket&) = delete;
   GenericRadialDataPacket& operator=(const GenericRadialDataPacket&) = delete;

   GenericRadialDataPacket(GenericRadialDataPacket&&) noexcept;
   GenericRadialDataPacket& operator=(GenericRadialDataPacket&&) noexcept;

   virtual int16_t  i_center_of_sweep() const     = 0;
   virtual int16_t  j_center_of_sweep() const     = 0;
   virtual uint16_t number_of_radials() const     = 0;
   virtual uint16_t number_of_range_bins() const  = 0;
   virtual float    start_angle(uint16_t r) const = 0;

   virtual const std::vector<uint8_t>& level(uint16_t r) const = 0;

private:
   std::unique_ptr<GenericRadialDataPacketImpl> p;
};

} // namespace rpg
} // namespace wsr88d
} // namespace scwx
