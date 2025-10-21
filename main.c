#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"
#include "ascii_db/ascii_table.h"
void test_case_1()
{
    printf("=== Test Case 1: Basic User Table ===\n");
    table_t *users = create_table("users");
    add_column(users, "uid", STRING);
    add_column(users, "name", STRING);
    add_column(users, "age", INT);

    val_t vals1[3] = {{.string = "123"}, {.string = "Malinga"}, {.i = 23}};
    val_t vals2[3] = {{.string = "124"}, {.string = "Nagaraj"}, {.i = 21}};
    val_t vals3[3] = {{.string = "125"}, {.string = "Shree Nath"}, {.i = 21}};

    add_row(users, vals1);
    add_row(users, vals2);
    add_row(users, vals3);

    print(users);
    destroy_table(users);
    printf("\n");
}

void test_case_2()
{
    printf("=== Test Case 2: Product Inventory ===\n");
    table_t *products = create_table("products");
    add_column(products, "id", INT);
    add_column(products, "name", STRING);
    add_column(products, "price", FLOAT);
    add_column(products, "in_stock", CHAR);

    val_t vals1[4] = {{.i = 1}, {.string = "Laptop"}, {.f = 999.99}, {.c = 'Y'}};
    val_t vals2[4] = {{.i = 2}, {.string = "Mouse"}, {.f = 25.50}, {.c = 'N'}};
    val_t vals3[4] = {{.i = 3}, {.string = "Keyboard"}, {.f = 75.00}, {.c = 'Y'}};

    add_row(products, vals1);
    add_row(products, vals2);
    add_row(products, vals3);

    print(products);
    destroy_table(products);
    printf("\n");
}

void test_case_3()
{
    printf("=== Test Case 3: Empty Table ===\n");
    table_t *empty = create_table("empty_table");
    add_column(empty, "col1", INT);
    add_column(empty, "col2", STRING);

    print(empty);
    destroy_table(empty);
    printf("\n");
}

void test_case_4()
{
    printf("=== Test Case 4: Single Row Table ===\n");
    table_t *single = create_table("single_row");
    add_column(single, "id", INT);
    add_column(single, "description", STRING);

    val_t vals[2] = {{.i = 100}, {.string = "Only one row"}};
    add_row(single, vals);

    print(single);
    destroy_table(single);
    printf("\n");
}

void test_case_5()
{
    printf("=== Test Case 5: Mixed Data Types ===\n");
    table_t *mixed = create_table("mixed_data");
    add_column(mixed, "integer", INT);
    add_column(mixed, "character", CHAR);
    add_column(mixed, "floating", FLOAT);
    add_column(mixed, "text", STRING);

    val_t vals1[4] = {{.i = 42}, {.c = 'A'}, {.f = 3.14}, {.string = "Hello"}};
    val_t vals2[4] = {{.i = -100}, {.c = 'Z'}, {.f = -2.5}, {.string = "World"}};
    val_t vals3[4] = {{.i = 0}, {.c = ' '}, {.f = 0.0}, {.string = "Test"}};

    add_row(mixed, vals1);
    add_row(mixed, vals2);
    add_row(mixed, vals3);

    print(mixed);
    destroy_table(mixed);
    printf("\n");
}

void test_case_6()
{
    printf("=== Test Case 6: Student Records ===\n");
    table_t *students = create_table("students");
    add_column(students, "roll_no", STRING);
    add_column(students, "full_name", STRING);
    add_column(students, "grade", CHAR);
    add_column(students, "gpa", FLOAT);

    val_t vals1[4] = {{.string = "CS001"}, {.string = "Alice Johnson"}, {.c = 'A'}, {.f = 3.8}};
    val_t vals2[4] = {{.string = "CS002"}, {.string = "Bob Smith"}, {.c = 'B'}, {.f = 3.2}};
    val_t vals3[4] = {{.string = "CS003"}, {.string = "Carol Davis"}, {.c = 'A'}, {.f = 3.9}};
    val_t vals4[4] = {{.string = "CS004"}, {.string = "David Wilson"}, {.c = 'C'}, {.f = 2.8}};

    add_row(students, vals1);
    add_row(students, vals2);
    add_row(students, vals3);
    add_row(students, vals4);

    print(students);
    destroy_table(students);
    printf("\n");
}

void test_case_7()
{
    printf("=== Test Case 7: Maximum Columns Test ===\n");
    table_t *max_cols = create_table("max_columns");

    // Add maximum allowed columns
    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        char col_name[20];
        snprintf(col_name, 20, "col_%d", i);
        add_column(max_cols, col_name, i % 4); // Cycle through types
    }

    val_t vals[MAX_COLUMNS];
    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        switch (i % 4)
        {
        case INT:
            vals[i].i = i * 10;
            break;
        case STRING:
            char str[20];
            snprintf(str, 20, "string_%d", i);
            vals[i].string = str;
            break;
        case CHAR:
            vals[i].c = 'A' + i;
            break;
        case FLOAT:
            vals[i].f = i * 1.1;
            break;
        }
    }

    add_row(max_cols, vals);
    print(max_cols);
    destroy_table(max_cols);
    printf("\n");
}

void test_case_8()
{
    printf("=== Test Case 8: Employee Database ===\n");
    table_t *employees = create_table("employees");
    add_column(employees, "emp_id", STRING);
    add_column(employees, "first_name", STRING);
    add_column(employees, "last_name", STRING);
    add_column(employees, "department", STRING);
    add_column(employees, "salary", FLOAT);

    val_t vals1[5] = {{.string = "E001"}, {.string = "John"}, {.string = "Doe"}, {.string = "IT"}, {.f = 75000.0}};
    val_t vals2[5] = {{.string = "E002"}, {.string = "Jane"}, {.string = "Smith"}, {.string = "HR"}, {.f = 65000.0}};
    val_t vals3[5] = {{.string = "E003"}, {.string = "Mike"}, {.string = "Brown"}, {.string = "Finance"}, {.f = 80000.0}};

    add_row(employees, vals1);
    add_row(employees, vals2);
    add_row(employees, vals3);

    print(employees);
    destroy_table(employees);
    printf("\n");
}

void test_case_9()
{
    printf("=== Test Case 9: Temperature Readings ===\n");
    table_t *temperatures = create_table("temperatures");
    add_column(temperatures, "city", STRING);
    add_column(temperatures, "temp_c", FLOAT);
    add_column(temperatures, "temp_f", FLOAT);
    add_column(temperatures, "humidity", INT);

    val_t vals1[4] = {{.string = "New York"}, {.f = 22.5}, {.f = 72.5}, {.i = 65}};
    val_t vals2[4] = {{.string = "London"}, {.f = 15.2}, {.f = 59.4}, {.i = 80}};
    val_t vals3[4] = {{.string = "Tokyo"}, {.f = 28.7}, {.f = 83.7}, {.i = 70}};
    val_t vals4[4] = {{.string = "Sydney"}, {.f = 30.1}, {.f = 86.2}, {.i = 45}};

    add_row(temperatures, vals1);
    add_row(temperatures, vals2);
    add_row(temperatures, vals3);
    add_row(temperatures, vals4);

    print(temperatures);
    destroy_table(temperatures);
    printf("\n");
}

void test_case_10()
{
    printf("=== Test Case 10: Book Collection ===\n");
    table_t *books = create_table("books");
    add_column(books, "isbn", STRING);
    add_column(books, "title", STRING);
    add_column(books, "author", STRING);
    add_column(books, "year", INT);
    add_column(books, "rating", FLOAT);

    val_t vals1[5] = {{.string = "978-0451524935"}, {.string = "1984"}, {.string = "George Orwell"}, {.i = 1949}, {.f = 4.7}};
    val_t vals2[5] = {{.string = "978-0061120084"}, {.string = "To Kill a Mockingbird"}, {.string = "Harper Lee"}, {.i = 1960}, {.f = 4.8}};
    val_t vals3[5] = {{.string = "978-0544003415"}, {.string = "The Lord of the Rings"}, {.string = "J.R.R. Tolkien"}, {.i = 1954}, {.f = 4.9}};

    add_row(books, vals1);
    add_row(books, vals2);
    add_row(books, vals3);

    print(books);
    destroy_table(books);
    printf("\n");
}

int main()
{
  printf("Database Library Test Suite\n");
  printf("===========================\n\n");
#ifdef TEST_1
  test_case_1(); // Basic user table
#endif
#ifdef TEST_2
  test_case_2(); // Product inventory
#endif
#ifdef TEST_3
  test_case_3(); // Empty table
#endif
#ifdef TEST_4
  test_case_4(); // Single row
#endif
#ifdef TEST_5
  test_case_5();  // Mixed data types
#endif
#ifdef TEST_6
  test_case_6();  // Student records
#endif
#ifdef TEST_7
  test_case_7();  // Maximum columns
#endif
#ifdef TEST_8
  test_case_8();  // Employee database
#endif
#ifdef TEST_9
  test_case_9();  // Temperature readings
#endif
#ifdef TEST_10
  test_case_10(); // Book collection
#endif
  printf("All test cases completed!\n");
  return 0;
}
