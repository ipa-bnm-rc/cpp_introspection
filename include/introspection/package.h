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

#ifndef CPP_INTROSPECTION_PACKAGE_H
#define CPP_INTROSPECTION_PACKAGE_H

#include <introspection/forwards.h>

namespace cpp_introspection {

  class Package
  {
  protected:
    V_Message messages_;

  private:
    struct G_Vars * gvars_;

  public:
    Package(struct G_Vars * gvars) : gvars_(gvars) {}
    virtual ~Package() {}
    static PackagePtr add(const PackagePtr& package);

    virtual const char *getName() const = 0;
    std::vector<std::string> getMessages() const;
    V_Message getMessageObjects() const;

    virtual const V_Message& fields() const { return messages_; }
    MessagePtr message(const std::string& message) const;

    typedef V_Message::iterator iterator;
    typedef V_Message::const_iterator const_iterator;
    const_iterator begin() const { return messages_.begin(); }
    const_iterator end() const   { return messages_.end(); }
    std::size_t size() const     { return messages_.size(); }

  protected:
    virtual MessagePtr add(const MessagePtr& message);
  };

  PackagePtr package(const std::string& pkg);
  static inline PackagePtr package(const char* pkg) { return package(std::string(pkg)); }
  const V_Package &packages();

} // namespace cpp_introspection

#endif // CPP_INTROSPECTION_PACKAGE_H
