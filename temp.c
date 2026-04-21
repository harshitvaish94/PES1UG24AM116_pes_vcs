#include "pes.h"
#include "tree.h"
#include <string.h>
#include <stdlib.h>

int main() {
    Tree t;
    t.count = 1;

    t.entries[0].mode = 0100644;
    strcpy(t.entries[0].name, "file.txt");
    memset(t.entries[0].hash.hash, 0xAA, HASH_SIZE);

    void *data;
    size_t len;

    tree_serialize(&t, &data, &len);

    ObjectID id;
    object_write(OBJ_TREE, data, len, &id);

    free(data);
    return 0;
}
