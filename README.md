# 🏦 Bank System Project 💼

> **A simple console-based application implementing object-oriented programming principles for efficient banking operations.**

---

## 🌟 Project Overview

This C++ Bank Management System provides a structured way to manage client and user accounts and handle financial transactions. The project utilizes object-oriented programming (OOP), basic data encryption, and file-based storage for secure and persistent data management.

---

## ✨ Features

### 📋 Object-Oriented Design
- Encapsulation of client and user data.
- Modular project structure with segmented functionality.

### 🔒 Security & Data Management
- **Caesar Cipher Encryption**: Ensures basic security for stored data.
- **File-Based Database**: Uses text files to store client and user records.

### 👥 Client Management
- ➕ **Add New Clients**
- 🗒️ **Update Client Details**
- ❌ **Delete Clients**
- 🔍 **Search for Clients**
- 🗂 **View All Clients**

### 💸 Financial Transactions
- 💰 **Deposit Funds**
- 💳 **Withdraw Money**
- 🔄 **Transfer Funds**
- 📊 **View Total Balances**

### 🤝 User Management
- ➕ **Add New Users**
- 🗒️ **Update User Details**
- ❌ **Delete Users**
- 🔍 **Search for Users**
- 🗂 **View All Users**
- 🔐 **Manage User Permissions**

### 🛡️ Permission Management
- **Role-based Access Control**
- Restrict functionalities based on user roles.

---

## 🛠️ Code Structure

### Classes
- **clsUser**: Represents the user with its data and related functions.
- **clsClientBank**: Represents the bank client with all related data and operations.

### Enumerations
- **enMainMenuPermissions**: Defines user roles.
- **enTransactionsMenuOptions**: Controls transaction operations.
- **enManageUsersMenuOptions**: Handles user-related actions.

### Functions
- **CRUD Operations**: Create, Read, Update, and Delete for users and clients.
- **Transaction Handling**: Deposit, withdraw, transfer.
- **File Management**: Functions for reading and writing client and user data securely from/to text files.

---

## 📚 Screens Implemented
- 🔐 Login Screen/Log Out 
- 📋 Main Menu Screen
- 💸 Transaction Screen (Deposit, Withdraw, Total Balances, Transfer)
- 📅 Client & User Management Screens

---

## 🔧 How It Works

1. **User Authentication**
   - Secure login/logout process.
   - Permission-based access to features.

2. **Client & User Management**
   - Add, edit, delete, and search clients and users.
   
3. **Financial Transactions**
   - Handle deposits, withdrawals, and balance tracking.
   
4. **File Handling**
   - Uses `Clients.txt` and `Users.txt` for persistent data storage.
   
---

## ⚙️ Technologies Used
- **Language**: C++
- **Programming Paradigm**: Object-Oriented Programming (OOP)
- **File Handling**: Text-based persistent storage

---

## 📚 License
This project is open-source. Feel free to use and modify it! 🎉

---

## 🤝 Contributions
Contributions are welcome! Submit a pull request with your improvements.

---

## 🏁 Getting Started

### ⚡ How to Run
1. **Clone the Repository** to your local machine.
2. **Compile** the C++ code using your preferred compiler (e.g., `g++`).
3. **Run** the executable and start managing banking operations!

---
