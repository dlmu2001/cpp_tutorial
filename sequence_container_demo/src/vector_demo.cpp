
#include "vector_demo.h"

VectorDemo::VectorDemo():items_(new vector<shared_ptr<TestItem>>()){
}
VectorDemo::~VectorDemo(){}
VectorDemo& VectorDemo::instance(){
    static VectorDemo sg;
    return sg;
}
int32_t VectorDemo::add_item(const string& name) {
   // 使用emplace_back代替push，实现原地构造,减少一次对象拷贝
   auto item = std::make_shared<TestItem>(++id_, name);
   items_->emplace_back(item);
   return id_; 
}
void VectorDemo::remove_item(int32_t id) {
   for(auto it = items_->begin(); it != items_->end(); ++it) {
     auto item = *it;
     if (item->id() == id) {
        items_->erase(it); 
        return;
     }
   } 
}
shared_ptr<TestItem> VectorDemo::get_item(int32_t id) {
   // 使用const iterator
   for(auto it = items_->cbegin(); it != items_->cend(); ++it) {
       auto item = *it;
       if (item->id() == id) {
         return item;
       }
   }
   return nullptr; 
}

void VectorDemo::set_item_dirty(int32_t id, bool dirty) {
    for(auto it = items_->begin(); it!= items_->end();++it) {
        auto item = *it;
        if (item->id() == id) {
            item->set_dirty(true);
        }
    }
}
void VectorDemo::remove_dirty_item() {
    for(auto it = items_->begin(); it!= items_->end();) {
        auto item = *it;
        if (item->dirty()) {
            // 注意在循环中erase 元素的时候，要将结果赋值给iterator，并且
            // 这个iterator已经增长过，不要在for循环体里进行++
            it = items_->erase(it);
        } else {
            ++it;
        }
    }
}
void VectorDemo::dump() {
    printf("\n items dump \n");
    for(auto item: *items_) {
        printf("\n    item: name(%s), id(%d), dirty(%d)\n", item->name().c_str(), item->id(), 
                item->dirty());
    }
}


