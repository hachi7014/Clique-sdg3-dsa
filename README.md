# 🩸 Blood Donation Management System (BDMS)

**UN SDG Alignment:**  
**SDG 3 – Good Health and Well-being**

---

##  Project Overview

The **Blood Donation Management System (BDMS)** is a console-based application designed to demonstrate the practical application of **Data Structures and Algorithms (DSA)** in solving a real-world resource management problem.

The primary objective of this system is to **minimize blood wastage** by ensuring efficient inventory control and prioritizing blood unit dispatch based on the **earliest expiration date**.

---

##  Problem Statement

Blood is a highly **perishable medical resource**. Inefficient tracking and manual handling of blood inventories often result in:

- Expired blood units
- Increased wastage
- Reduced availability for patients in need

This project addresses these challenges by implementing optimized data handling techniques to ensure timely and efficient blood distribution.

---

##  Solution Approach

The system applies three core Data Structures to balance **efficiency**, **speed**, and **accuracy**:

| Data Structure | Function | Time Complexity |
|-----------------|----------|------------------|
| **Min Priority Queue (Min Heap)** | Dispatches blood units based on the earliest expiration | `O(log n)` |
| **Binary Search** | Searches for individual blood unit IDs | `O(log n)` |
| **Linked List** | Temporarily stores parsed CSV records | `O(1)` insertion |

---

##  System Features

- Load and parse blood inventory data from CSV files  
- Manage and store blood units using DSA-based structures  
- Dispatch blood units by priority (earliest expiration first)  
- Search inventory by **Unit ID**  
- Display inventory status through a **menu-driven console interface**

---

##  Installation & Setup

###  Requirements

- C++ compiler (**GCC** or **MinGW**)
- Terminal / Command Prompt

---

###  Clone the Repository
git clone [YOUR GITHUB REPO URL HERE]
cd Clique-sdg3-dsa

### Compile the Program
g++ CODE/main.cpp CODE/DataParser.cpp CODE/MinPriorityQueue.cpp CODE/InventorySearch.cpp CODE/BloodUnit.cpp -o project_bdms

### Running the Application
./project_bdms

---

### Runtime Features
| Option | Functionality               | Requirement     | Complexity |
| ------ | --------------------------- | --------------- | ---------- |
| **1**  | Dispatch top priority unit  | FR3             | `O(log n)` |
| **2**  | Search for blood unit by ID | Midterm Feature | `O(log n)` |
| **3**  | Check current priority unit | FR4             | `O(1)`     |
| **0**  | Exit system                 | —               | —          |

---

### Testing
To verify that the priority queue is functioning correctly:
- Press 3 → View the current highest priority unit
- Press 1 → Dispatch that unit
- Press 3 again → Confirm the next closest-to-expiration unit is now at the top

---

### Project Contributors
| Name | Primary Role / Module |
| :--- | :--- |
| **Roldan, Christian Maverick Z.** | Lead Integrator, **MinPriorityQueue (Min Heap) Logic**, Final Testing/Debugging |
| **Musngi, Trishia** | **DataParser (Linked List) Implementation**, SDAD Design/Formatting |
| **Comcom, John Vincent** | **InventorySearch (Binary Search) Implementation**, Flowchart Design/Diagram |
| **Nivales, Ande Jexer** | **BloodUnit Class Implementation**, README/Usage Documentation |
| **Soriano, Mak** | **Input/Output Handling & Menu Logic (main.cpp)**, Final Data Validation |