#include <stdio.h>
#include "vector_demo.h"

int main(int argc,char *argv[]) {
    printf("Hello World!\n");
    printf("argc=%d]\n",argc);
    printf("argv[0]=%s\n",argv[0]);

    int32_t id1 = VectorDemo::instance().add_item("item1");
    int32_t id2 = VectorDemo::instance().add_item("item2");
    int32_t id3 = VectorDemo::instance().add_item("item3");
    int32_t id4 = VectorDemo::instance().add_item("item3");

    VectorDemo::instance().dump();
    
    auto item = VectorDemo::instance().get_item(id2);
    if (item) {
        printf("\n item 2: name(%s), id(%d), dirty(%d)", item->name().c_str(),
                item->id(), item->dirty());
    } else {
        printf("\n item not found");
    }
    VectorDemo::instance().set_item_dirty(id1,true);
    VectorDemo::instance().set_item_dirty(id3,true);
    printf("\n remove dirty item: 1,3 \n");
    VectorDemo::instance().remove_dirty_item();
    VectorDemo::instance().dump();

    printf("\n remove item2 \n");
    VectorDemo::instance().remove_item(id2);
    VectorDemo::instance().dump();
   return 0;
}

