# 📘 Student Record Management System (C Language)

This is a **console-based Student Record Management System** written in C. It allows users to manage student records using binary file handling. The program supports the following operations:

- Add a new student record
- Update an existing record
- List all student records
- Delete a student record
- Exit the program

## 📁 Files Used

- `student.bin`: Stores the student records persistently.
- `temp.bin`: Temporary file used during deletion.

---

## 🔧 Features

1. **Add Record**  
   Add a new student by entering their name, age, and admission year.

2. **Update Record**  
   Search and update a student's details by name.

3. **List Record**  
   Display all saved student records.

4. **Delete Record**  
   Delete a student record by name (with confirmation).

5. **Exit**  
   Safely close the program and save all changes.

---

## 🧑‍💻 Structure

```c
struct student {
    char name[100];
    int age;
    int admitionYear;
};
```

---

## 🛠 How It Works

1. **Startup**:
   - Tries to open `student.bin` in `rb+` mode.
   - If it doesn’t exist, creates a new file with `wb+`.

2. **Main Menu**:
   - Displayed via `getChoice()` with options from 0–4.

3. **File Handling**:
   - Records are written using `fwrite()` and read using `fread()`.
   - Deleted records are filtered and rewritten to a temp file.

4. **Screen Handling**:
   - Uses `system("cls")` for clearing screen (works on Windows).
   - `holdScreen()` is used to pause execution until a key is pressed.

---

## ⚠ Notes

- Works on **Windows OS** (due to use of `system("cls")`).
- Binary file `student.bin` stores the actual data.
- Input buffer is carefully managed using `getchar()` and `fgets()`.

---

## 📦 Future Improvements (Optional Ideas)

- Add unique roll numbers or IDs to manage duplicate names.
- Allow partial search for names.
- Implement sorting or filtering of records.
- Make it cross-platform (remove `system("cls")`).

---

## ▶ Run Instructions

1. Compile the code using any C compiler:
   ```bash
   gcc student.c -o student
   ```

2. Run the executable:
   ```bash
   ./student
   ```

   > If you're using Windows:
   ```bash
   student.exe
   ```

---

## 📄 License

This project is open-source and free to use for learning and educational purposes.