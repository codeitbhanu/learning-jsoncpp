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
  void set_name(string name);
  void set_phone_number(string phone_number);
  string name() const;
  string phone_number() const;
  Json::Value ToJson() const;
};

class AddressBook {
private:
  vector<Contact> contacts_;
public:
  AddressBook();
  vector<Contact> contacts() const;
  void JsonSave(const char* filename);
  void JsonLoad(const char* filename);

  void AddPerson(string name, string phone_number);
};
