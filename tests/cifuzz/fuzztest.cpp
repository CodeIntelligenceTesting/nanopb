#include <assert.h>
#include <cstddef>
#include <cstdint>

#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>

#include "pb_decode.h"
#include "tests/alltypes/alltypes.pb.h"


FUZZ_TEST_SETUP() {}

FUZZ_TEST(const uint8_t *data, size_t size) {
    AllTypes msg = AllTypes_init_zero;
    pb_istream_t stream = pb_istream_from_buffer(data, size);
    pb_decode(&stream, AllTypes_fields, &msg);
}
