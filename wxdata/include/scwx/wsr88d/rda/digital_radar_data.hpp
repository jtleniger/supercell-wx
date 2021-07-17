#pragma once

#include <scwx/wsr88d/rda/message.hpp>

namespace scwx
{
namespace wsr88d
{
namespace rda
{

enum class DataBlockType
{
   Volume,
   Elevation,
   Radial,
   MomentRef,
   MomentVel,
   MomentSw,
   MomentZdr,
   MomentPhi,
   MomentRho,
   MomentCfp,
   Unknown
};

class DataBlockImpl;
class ElevationDataBlockImpl;
class MomentDataBlockImpl;
class RadialDataBlockImpl;
class VolumeDataBlockImpl;

class DigitalRadarDataImpl;

class DataBlock
{
protected:
   explicit DataBlock(const std::string& dataBlockType,
                      const std::string& dataName);
   ~DataBlock();

   DataBlock(const DataBlock&) = delete;
   DataBlock& operator=(const DataBlock&) = delete;

   DataBlock(DataBlock&&) noexcept;
   DataBlock& operator=(DataBlock&&) noexcept;

private:
   std::unique_ptr<DataBlockImpl> p;
};

class ElevationDataBlock : public DataBlock
{
public:
   explicit ElevationDataBlock(const std::string& dataBlockType,
                               const std::string& dataName);
   ~ElevationDataBlock();

   ElevationDataBlock(const ElevationDataBlock&) = delete;
   ElevationDataBlock& operator=(const ElevationDataBlock&) = delete;

   ElevationDataBlock(ElevationDataBlock&&) noexcept;
   ElevationDataBlock& operator=(ElevationDataBlock&&) noexcept;

   static std::shared_ptr<ElevationDataBlock>
   Create(const std::string& dataBlockType,
          const std::string& dataName,
          std::istream&      is);

private:
   std::unique_ptr<ElevationDataBlockImpl> p;

   bool Parse(std::istream& is);
};

class MomentDataBlock : public DataBlock
{
public:
   explicit MomentDataBlock(const std::string& dataBlockType,
                            const std::string& dataName);
   ~MomentDataBlock();

   MomentDataBlock(const MomentDataBlock&) = delete;
   MomentDataBlock& operator=(const MomentDataBlock&) = delete;

   MomentDataBlock(MomentDataBlock&&) noexcept;
   MomentDataBlock& operator=(MomentDataBlock&&) noexcept;

   uint16_t    number_of_data_moment_gates() const;
   float       data_moment_range() const;
   float       data_moment_range_sample_interval() const;
   float       snr_threshold() const;
   uint8_t     data_word_size() const;
   float       scale() const;
   float       offset() const;
   const void* data_moments() const;

   static std::shared_ptr<MomentDataBlock>
   Create(const std::string& dataBlockType,
          const std::string& dataName,
          std::istream&      is);

private:
   std::unique_ptr<MomentDataBlockImpl> p;

   bool Parse(std::istream& is);
};

class RadialDataBlock : public DataBlock
{
public:
   explicit RadialDataBlock(const std::string& dataBlockType,
                            const std::string& dataName);
   ~RadialDataBlock();

   RadialDataBlock(const RadialDataBlock&) = delete;
   RadialDataBlock& operator=(const RadialDataBlock&) = delete;

   RadialDataBlock(RadialDataBlock&&) noexcept;
   RadialDataBlock& operator=(RadialDataBlock&&) noexcept;

   static std::shared_ptr<RadialDataBlock>
   Create(const std::string& dataBlockType,
          const std::string& dataName,
          std::istream&      is);

private:
   std::unique_ptr<RadialDataBlockImpl> p;

   bool Parse(std::istream& is);
};

class VolumeDataBlock : public DataBlock
{
public:
   explicit VolumeDataBlock(const std::string& dataBlockType,
                            const std::string& dataName);
   ~VolumeDataBlock();

   VolumeDataBlock(const VolumeDataBlock&) = delete;
   VolumeDataBlock& operator=(const VolumeDataBlock&) = delete;

   VolumeDataBlock(VolumeDataBlock&&) noexcept;
   VolumeDataBlock& operator=(VolumeDataBlock&&) noexcept;

   static std::shared_ptr<VolumeDataBlock>
   Create(const std::string& dataBlockType,
          const std::string& dataName,
          std::istream&      is);

private:
   std::unique_ptr<VolumeDataBlockImpl> p;

   bool Parse(std::istream& is);
};

class DigitalRadarData : public Message
{
public:
   explicit DigitalRadarData();
   ~DigitalRadarData();

   DigitalRadarData(const DigitalRadarData&) = delete;
   DigitalRadarData& operator=(const DigitalRadarData&) = delete;

   DigitalRadarData(DigitalRadarData&&) noexcept;
   DigitalRadarData& operator=(DigitalRadarData&&) noexcept;

   const std::string& radar_identifier() const;
   uint32_t           collection_time() const;
   uint16_t           modified_julian_date() const;
   uint16_t           azimuth_number() const;
   float              azimuth_angle() const;
   uint8_t            compression_indicator() const;
   uint16_t           radial_length() const;
   uint8_t            azimuth_resolution_spacing() const;
   uint8_t            radial_status() const;
   uint8_t            elevation_number() const;
   uint8_t            cut_sector_number() const;
   float              elevation_angle() const;
   uint8_t            radial_spot_blanking_status() const;
   uint8_t            azimuth_indexing_mode() const;
   uint16_t           data_block_count() const;

   std::shared_ptr<MomentDataBlock> moment_data_block(DataBlockType type) const;

   bool Parse(std::istream& is);

   static std::shared_ptr<DigitalRadarData> Create(MessageHeader&& header,
                                                   std::istream&   is);

private:
   std::unique_ptr<DigitalRadarDataImpl> p;
};

} // namespace rda
} // namespace wsr88d
} // namespace scwx