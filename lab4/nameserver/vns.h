#ifndef VNS_H
#define VNS_H

#include <vector>
#include "nameserverinterface.h"

using namespace std;

class VNS : public NameServerInterface {
public:
  virtual void insert(const HostName&, const IPAddress&) override;
  virtual bool remove(const HostName&) override;
  virtual IPAddress lookup(const HostName&) const override;
private:
  vector<pair<HostName, IPAddress>> database;
};

#endif
