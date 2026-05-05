**Shell Inventory Management System** is a desktop application designed for managing artillery shell inventory.

It allows users to:
- Add and remove shells from stock
- Track all inventory operations
- Filter and sort historical data
- Store data locally using SQLite

The project is built using **Qt (QML + C++)** with a clean model-view architecture.

---

## ⚙️ Features

- 📦 Inventory management (Add / Remove shells)
- 📊 Real-time inventory updates
- 🧾 Persistent history tracking (SQLite)
- 🔎 Filter history by shell type
- ↕️ Sort inventory by:
  - Shell Type
  - In Stock
  - Used
- 🖥️ Modern QML-based UI
- 💾 Local database storage

---

## 🧱 Tech Stack

| Layer        | Technology |
|--------------|-----------|
| Language      | C++ (C++17) |
| UI            | Qt Quick / QML |
| Database      | SQLite (Qt SQL) |
| Architecture  | Model / View / Proxy Models |

---

## 🏗️ Architecture

The project follows a modular Qt Model/View design:

### 📦 Models
- `InventoryListModel` → core inventory data
- `HistoryListModel` → stores operation history
- `InventorySortListModel` → sorting proxy model
- `HistoryFilterListModel` → filtering proxy model

### 🧠 Core Controller
- `InventoryManager`
  - Handles all business logic
  - Connects UI with models
  - Manages inventory operations

### 💾 Database Layer
- `DatabaseManager`
  - Initializes SQLite database
  - Inserts and retrieves history records

---

## 🗄️ Database Schema

**Table: `inventory`**

| Field        | Type    | Description |
|--------------|--------|-------------|
| id           | INTEGER | Primary key |
| date_time    | TEXT    | Operation time |
| action_type  | TEXT    | Added / Removed |
| shell_type   | TEXT    | Type of shell |
| quantity     | INTEGER | Amount |

---

## 🖥️ UI Structure

### 📍 Main Screen
- Inventory table view
- Add / Remove shell controls
- Sorting options
- Navigation to history

### 📜 History Page
- Full action log
- Filtering by shell type
- Displays:
  - Action
  - Type
  - Amount
  - Timestamp

### ✏️ Edit Dialog
- Select shell type
- Enter quantity
- Confirm Add / Remove

---

## 🚀 How It Works

1. User performs add/remove action
2. `InventoryManager` updates inventory model
3. Change is immediately reflected in UI
4. Action is stored in SQLite database
5. History model is updated automatically

---

## ▶️ Build & Run

### Requirements
- Qt 5 or Qt 6
- CMake (optional depending on setup)
- SQLite (included in Qt)
