#ifndef SRC_VECTOR_DEMO_H_
#define SRC_VECTOR_DEMO_H_
#include <memory>
#include <vector>
#include "test_item.h"

using std::string;
using std::shared_ptr;
using std::vector;
/**
 * this class demonstrate the usage of vector
 */
class VectorDemo {
 public:
     VectorDemo();
     ~VectorDemo();
     int32_t add_item(const string& name);
     void remove_item(int32_t id);
     shared_ptr<TestItem> get_item(int32_t id);
     void set_item_dirty(int32_t id, bool dirty);
     void remove_dirty_item();
     void dump();

     static VectorDemo& instance();
 private:
     shared_ptr<vector<shared_ptr<TestItem>>> items_;
     int32_t id_{0};
     void operator=(const VectorDemo&) = delete;
     VectorDemo(const VectorDemo&) = delete;
};
#endif
