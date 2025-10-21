
# Database Library

A lightweight in-memory database library written in C that provides table creation, data manipulation, and formatted ASCII table output capabilities.

## Features

- **Table Management**: Create and destroy tables with custom schemas
- **Multiple Data Types**: Support for INT, FLOAT, CHAR, and STRING types
- **Memory Safe**: Robust memory management with protection against buffer overflows
- **Formatted Output**: Beautiful ASCII table formatting for data visualization
- **Comprehensive Testing**: Extensive test suite covering various use cases

## Data Types Supported

- `INT` - Integer values
- `FLOAT` - Floating-point numbers  
- `CHAR` - Single characters
- `STRING` - String values (dynamically allocated)

## Quick Start

```c
#include "db.h"
#include "ascii_db/ascii_table.h"

// Create a table
table_t *users = create_table("users");
add_column(users, "id", INT);
add_column(users, "name", STRING);
add_column(users, "age", INT);

// Add data
val_t row1[3] = {{.i = 1}, {.string = "Alice"}, {.i = 25}};
val_t row2[3] = {{.i = 2}, {.string = "Bob"}, {.i = 30}};
add_row(users, row1);
add_row(users, row2);

// Display table
print(users);

// Cleanup
destroy_table(users);
```

## API Reference

### Core Functions

- `table_t* create_table(const char* name)` - Create new table
- `void add_column(table_t* table, const char* name, data_type_t type)` - Add column to table
- `void add_row(table_t* table, val_t* values)` - Insert row of data
- `void print(table_t* table)` - Display formatted table
- `void destroy_table(table_t* table)` - Free table memory

### Value Structure

```c
typedef union {
    int i;
    float f;
    char c;
    char* string;
} val_t;
```

## Building and Testing

```bash
# Build all test executables
make build_all

# Run specific test
make run_test_4

# Run complete test suite
make test_all

# Clean build artifacts
make clean
```

## Test Cases

The library includes comprehensive test coverage:

1. **Basic User Table** - Simple user data management
2. **Product Inventory** - Mixed data types with business data
3. **Empty Table** - Edge case with no rows
4. **Single Row Table** - Minimal data set
5. **Mixed Data Types** - All supported types in one table
6. **Student Records** - Academic data structure
7. **Maximum Columns** - Stress test for column limits
8. **Employee Database** - Complex business data
9. **Temperature Readings** - Scientific data formatting
10. **Book Collection** - Library management example

## Memory Safety

This library implements robust memory management:

- **Dynamic Allocation**: Strings are properly allocated and freed
- **Buffer Overflow Protection**: All string operations use exact-sized buffers
- **Leak Prevention**: Comprehensive cleanup in `destroy_table()`
- **Sanitizer Ready**: Compatible with AddressSanitizer for debugging

## Example Output

```
+-------+-------------+-------+
|  uid  |    name     |  age  |
+-------+-------------+-------+
| 123   | Malinga     | 23    |
| 124   | Nagaraj     | 21    |
| 125   | Shree Nath  | 21    |
+-------+-------------+-------+
```

## License

[Your License Here]

## Contributing

1. Ensure all tests pass: `make test_all`
2. Run with AddressSanitizer for memory checking
3. Follow existing code style and patterns
4. Add tests for new functionality

