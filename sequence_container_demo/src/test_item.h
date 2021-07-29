/**
 * a class to define data to be operated
 */

#ifndef SRC_TEST_ITEM_H_
#define SRC_TEST_ITEM_H_

#include <stdint.h>
#include <string>

class TestItem {
 public:
     TestItem(int32_t id, const std::string& name);
     ~TestItem();
     int32_t id(){
        return id_;
     }
     void set_id(int32_t id) {
        id_ = id;
     }
     std::string name() const {
        return name_;
     }
     void set_name(const std::string& name) {
        name_ = name;
     }
     void set_dirty(bool dirty){
        dirty_ = dirty;
     }
     bool dirty(){
        return dirty_;
     }
 private:
    int32_t id_{-1};
    bool dirty_{false};
    std::string name_;
};

#endif
