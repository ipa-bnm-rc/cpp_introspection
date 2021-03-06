//=================================================================================================
// Copyright (c) 2011, Johannes Meyer, TU Darmstadt
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the Flight Systems and Automatic Control group,
//       TU Darmstadt, nor the names of its contributors may be used to
//       endorse or promote products derived from this software without
//       specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//=================================================================================================

#ifndef CPP_INTROSPECTION_H
#define CPP_INTROSPECTION_H

#include <introspection/forwards.h>
#include <introspection/package.h>
#include <introspection/message.h>
#include <introspection/field.h>

namespace cpp_introspection {

//  extern M_Package g_packages;
//  extern V_Package g_repository;
//  extern M_Message g_messages_by_name;
//  extern M_Message g_messages_by_md5sum;
//  extern M_TypeInfo_Message g_messages_by_typeid;
//  extern V_string g_loaded_libraries;

  struct G_Vars {
	   M_Package g_packages;
	   V_Package g_repository;
	   M_Message g_messages_by_name;
	   M_Message g_messages_by_md5sum;
	   M_TypeInfo_Message g_messages_by_typeid;
	   V_string g_loaded_libraries;
  };

  extern G_Vars * gvars;

  PackagePtr loadPackage(const std::string& package_name);
  PackagePtr load(const std::string& package_or_library_or_path);

  template <typename T> MessagePtr introspect(T& instance) {
    MessagePtr message = messageByTypeId(typeid(T));
    if (!message) return MessagePtr();
    return message->introspect(&instance);
  }

} // namespace cpp_introspection

#endif // CPP_INTROSPECTION_H
