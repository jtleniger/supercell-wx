#pragma once

#ifdef _WIN32
#include <Windows.h>
#endif

#include <memory>
#include <string>

#include <GL/gl.h>

namespace scwx
{
namespace qt
{

class ShaderProgramImpl;

class ShaderProgram
{
public:
   explicit ShaderProgram();
   ~ShaderProgram();

   ShaderProgram(const ShaderProgram&) = delete;
   ShaderProgram& operator=(const ShaderProgram&) = delete;

   ShaderProgram(ShaderProgram&&) noexcept;
   ShaderProgram& operator=(ShaderProgram&&) noexcept;

   GLuint id() const;

   bool Load(const std::string& vertexPath, const std::string& fragmentPath);

   void Use() const;

private:
   std::unique_ptr<ShaderProgramImpl> p;
};

} // namespace qt
} // namespace scwx
