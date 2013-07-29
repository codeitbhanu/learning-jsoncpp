#include "addressbook.h"

Contact::Contact() {
  set_name("unnamed");
  set_phone_number("000-000-0000");
}

void Contact::set_name(string name) {
  name_ = name;
}

void Contact::set_phone_number(string phone_number) {
  phone_number_ = phone_number;
}

string Contact::name() const {
  return name_;
}

string Contact::phone_number() const {
  return phone_number_;
}

Json::Value Contact::ToJson() const {
  Json::Value value(Json::objectValue);
  value["name"] = name_;
  value["phone_number"] = phone_number_;
  return value;
}

AddressBook::AddressBook() {
  contacts_ = vector<Contact>();
}

vector<Contact> AddressBook::contacts() const {
  return contacts_;
}

void AddressBook::AddPerson(string name, string phone_number) {
  Contact contact = Contact();
  contact.set_name(name);
  contact.set_phone_number(phone_number);
  contacts_.push_back(contact);
}

void AddressBook::JsonSave(const char* filename) {
  ofstream out(filename, ofstream::out);
  Json::Value book_json(Json::objectValue), contacts_json(Json::arrayValue);
  for (vector<Contact>::iterator it = contacts_.begin(); it != contacts_.end(); ++it) {
    contacts_json.append((*it).ToJson());
  }
  book_json["contacts"] = contacts_json;
  out << book_json;
  out.close();
}

void AddressBook::JsonLoad(const char* filename) {
  ifstream in(filename);
  Json::Value book_json;
  in >> book_json;
  in.close();
}