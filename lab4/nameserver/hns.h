#ifndef HNS_H
#define HNS_H

#include <vector>
#include "nameserverinterface.h"
#include <functional>
#include <string>

using namespace std;

class HNS : public NameServerInterface {
public:
  HNS(int);
  virtual void insert(const HostName&, const IPAddress&) override;
  virtual bool remove(const HostName&) override;
  virtual IPAddress lookup(const HostName&) const override;
private:
  vector<vector<pair<HostName, IPAddress>>> database;
  hash<string> str_hash;
};

#endif
