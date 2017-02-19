#ifndef MNS_H
#define MNS_H

#include <vector>
#include "nameserverinterface.h"
#include <map>

using namespace std;

class MNS : public NameServerInterface {
public:
  virtual void insert(const HostName&, const IPAddress&) override;
  virtual bool remove(const HostName&) override;
  virtual IPAddress lookup(const HostName&) const override;
private:
  map<HostName, IPAddress> database;
};

#endif
