// -*- mode: c++ -*-
#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "json/json.h"

using namespace std;

class Contact {
private:
  string name_;
  string phone_number_;
public:
  Contact();
  void set_name(const string &name);
  void set_phone_number(const string &phone_number);
  const string& name() const;
  const string& phone_number() const;
  Json::Value ToJson() const;
};

class AddressBook {
private:
  vector<Contact> contacts_;
public:
  AddressBook();
  const vector<Contact>& contacts() const;
  void JsonSave(const char* filename);
  void JsonLoad(const char* filename);

  void AddPerson(const string &name, const string &phone_number);
  const vector<Contact>::iterator& begin();
  const vector<Contact>::iterator& end();
};
