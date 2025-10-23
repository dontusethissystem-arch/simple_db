CC = gcc
INCLUDES=-I.

SRC = main.c db.c ascii_db/ascii_table.c
HEADERS = db.h ascii_db/ascii_table.h
TEST_DIR=tests
$(TEST_DIR):
	mkdir -p $(TEST_DIR)

$(TEST_DIR)/test_1: $(SRC) $(HEADERS)
	$(CC) $(INCLUDES) -DTEST_1 -o $@ $(SRC)
$(TEST_DIR)/test_2: $(SRC) $(HEADERS)
	$(CC) $(INCLUDES) -DTEST_2 -o $@ $(SRC)
$(TEST_DIR)/test_3: $(SRC) $(HEADERS)
	$(CC) $(INCLUDES) -DTEST_3 -o $@ $(SRC)
$(TEST_DIR)/test_4: $(SRC) $(HEADERS)
	$(CC) $(INCLUDES) -DTEST_4 -o $@ $(SRC)
$(TEST_DIR)/test_5: $(SRC) $(HEADERS)
	$(CC) $(INCLUDES) -DTEST_5 -o $@ $(SRC)
$(TEST_DIR)/test_6: $(SRC) $(HEADERS)
	$(CC) $(INCLUDES) -DTEST_6 -o $@ $(SRC)
$(TEST_DIR)/test_7: $(SRC) $(HEADERS)
	$(CC) $(INCLUDES) -DTEST_7 -o $@ $(SRC)
$(TEST_DIR)/test_8:	$(SRC) $(HEADERS) 
	$(CC) $(INCLUDES) -DTEST_8 -o $@ $(SRC)
$(TEST_DIR)/test_9: $(SRC) $(HEADERS)
	$(CC) $(INCLUDES) -DTEST_9 -o $@ $(SRC)
$(TEST_DIR)/test_10: $(SRC) $(HEADERS)
	$(CC) $(INCLUDES) -DTEST_10 -o $@ $(SRC)


test_1: $(TEST_DIR)/test_1
test_2: $(TEST_DIR)/test_2
test_3: $(TEST_DIR)/test_3
test_4: $(TEST_DIR)/test_4
test_5: $(TEST_DIR)/test_5
test_6: $(TEST_DIR)/test_6
test_7: $(TEST_DIR)/test_7
test_8: $(TEST_DIR)/test_8
test_9: $(TEST_DIR)/test_9
test_10: $(TEST_DIR)/test_10
all: test_1 test_2 test_3 test_4 test_5 test_6 test_7 test_8 test_9 test_10
clean:
	rm $(TEST_DIR)/test_*
