#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

void allocationError() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

void sizeError() {
    fprintf(stderr, "size error");
    exit(1);
}

void indexError(size_t index) {
    fprintf(stderr, "IndexError: a[%zu] is not exists", index);
    exit(1);
}
