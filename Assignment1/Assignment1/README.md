Circular Buffer – CE-ESY Assignment

This project implements a simple Circular Buffer using the C programming language.  
The program reads the user's name, appends the string "CE-ESY" to it, stores each character inside a fixed‑size circular buffer, and then reads and prints the stored data.

📌 Program Components

1. Circular Buffer Structure
The buffer is implemented using a struct that contains:
- buffer[] → array for storing characters  
- head → read index  
- tail → write index  
- count → number of stored elements  
- SIZE → fixed buffer size (defined using #define)

📌 Functions Overview

✔ init()
Initializes the buffer:
- head = 0
- tail = 0
- count = 0

✔ isFull()
Returns true if the buffer is full.

✔ isEmpty()
Returns true if the buffer is empty.

✔ write()
Writes a character into the buffer.  
If the buffer is full → prints "Buffer Overflow" and does not write.

✔ read()
Reads a character from the buffer.  
If the buffer is empty → prints "Buffer Underflow" and returns '\0'.

📌 Program Flow (main)

1. Create a CircularBuffer variable.
2. Initialize it using init().
3. Read the user's name using fgets().
4. Remove the newline character.
5. Append the string "CE-ESY" to the name using strcat().
6. Print:
   - The final text
   - Buffer size
   - Text length
7. Write each character of the text into the circular buffer using write().
8. Read and print characters using read() until the buffer becomes empty.
9. Print the final state of the buffer.
📌 Important Notes
- The buffer size is fixed: SIZE = 5
- If the text is longer than the buffer capacity, Buffer Overflow messages will appear  
  → This is expected behavior and demonstrates how a circular buffer works.

📌 Example Output
Enter your name: Leen

Final text to store: LeenCE-ESY
Buffer size: 5
Text length: 10

Buffer Overflow! cannot write 'n'
Buffer Overflow! cannot write 'C'
...

-- Reading from buffer --
LeenC

Buffer is now empty (isEmpty = 1)
📌 How to Run
To run the program on any C compiler:

1. Copy the code into a file named prog.c
2. Compile the file
3. Run the program
4. Enter your name when prompted
5. Observe how the circular buffer stores and reads the data
يعني كود ريدمي يليلي بعتلي ياه هاد زابط مع الكود

include <stdio.h>

include <string.h>

include <stdbool.h>

define SIZE 5   // غيّر إلى 3 مرة وأقل من طول النص، وإلى 10 مرة أكبر

typedef struct {
    char buffer[SIZE];
    int head;     // مؤشر القراءة
    int tail;     // مؤشر الكتابة
    int count;    // عدد العناصر الموجودة حالياً
} CircularBuffer;

void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

bool isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

bool isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

// الكتابة: إضافة حرف
void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow! لا يمكن كتابة '%c'\n", data);
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

// القراءة: استخراج حرف
char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow! لا توجد بيانات للقراءة\n");
        return '\0';
    }
    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;
    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[100];

    // إدخال الاسم من المستخدم
    printf("أدخل اسمك: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // إزالة newline

    // إضافة السلسلة "CE-ESY"
    char toAppend[] = "CE-ESY";
    strcat(name, toAppend);

    printf("\nالنص المراد تخزينه: %s\n", name);
    printf("حجم المخزن: %d\n", SIZE);
    printf("طول النص: %zu\n\n", strlen(name));

    // كتابة كل حرف في المخزن الدائري
    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    printf("\n-- قراءة البيانات من المخزن --\n");
    // القراءة والعرض حتى يصبح المخزن فارغاً
    while (!isEmpty(&cb)) {
        char ch = read(&cb);
        if (ch != '\0')
            printf("%c", ch);
    }
    printf("\n\nالمخزن الآن فارغ (isEmpty = %d)\n", isEmpty(&cb));

    return 0;
}
