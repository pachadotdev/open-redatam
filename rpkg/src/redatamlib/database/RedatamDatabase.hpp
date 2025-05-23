#ifndef REDATAMLIB_REDATAMDATABASE_HPP
#define REDATAMLIB_REDATAMDATABASE_HPP

#include "Entity.hpp"
#include <cpp11/list.hpp>

namespace RedatamLib {
using std::string;
using std::vector;

class RedatamDatabase {
public:
  // Throws invalid_argument
  explicit RedatamDatabase(const string &fileName);
  ~RedatamDatabase() = default;

  RedatamDatabase(const RedatamDatabase &) = delete;
  RedatamDatabase &operator=(const RedatamDatabase &) = delete;

  cpp11::list ExportRLists() const;

private:
  vector<Entity> m_entities;

  void OpenDictionary(const string &fileName);
};

} // namespace RedatamLib

#endif // REDATAMLIB_REDATAMDATABASE_HPP
