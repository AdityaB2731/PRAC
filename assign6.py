def evaluate_employee():

    print("\n=== EMPLOYEE PERFORMANCE EVALUATION SYSTEM ===\n")

    name = input("Enter Employee Name: ")

    print("\nRate Employee From 1 to 10\n")

    communication = int(input("Communication Skills: "))
    teamwork = int(input("Teamwork: "))
    punctuality = int(input("Punctuality: "))
    productivity = int(input("Productivity: "))
    leadership = int(input("Leadership: "))

    total = (
        communication +
        teamwork +
        punctuality +
        productivity +
        leadership
    )

    average = total / 5

    print("\n----- PERFORMANCE REPORT -----")

    print("Employee Name :", name)
    print("Total Score   :", total)
    print("Average Score :", average)

    if average >= 8:

        print("\nPerformance Level : Excellent")
        print("Promotion Recommended")

    elif average >= 6:

        print("\nPerformance Level : Good")
        print("Increment Recommended")

    elif average >= 4:

        print("\nPerformance Level : Average")
        print("Training Recommended")

    else:

        print("\nPerformance Level : Poor")
        print("Needs Serious Improvement")


while True:

    print("\n========== MENU ==========")

    print("1. Evaluate Employee")
    print("2. Exit")

    choice = int(input("\nEnter Your Choice: "))

    if choice == 1:

        evaluate_employee()

    elif choice == 2:

        print("\nExiting Program...")
        break

    else:

        print("\nInvalid Choice!")


# <!DOCTYPE html>
# <html>
# <head>
#     <title>Medical Expert System</title>
# </head>

# <body>

# <div class="container">

#     <h2>Medical Expert System</h2>

#     <label>
#         <input type="checkbox" id="fever">
#         Fever
#     </label>

#     <br><br>

#     <label>
#         <input type="checkbox" id="cough">
#         Cough
#     </label>

#     <br><br>

#     <label>
#         <input type="checkbox" id="headache">
#         Headache
#     </label>

#     <br><br>

#     <label>
#         <input type="checkbox" id="fatigue">
#         Fatigue
#     </label>

#     <br><br>

#     <label>
#         <input type="checkbox" id="breathing">
#         Breathing Problem
#     </label>

#     <br><br>

#     <button onclick="diagnose()">
#         Diagnose
#     </button>

#     <h3 id="result"></h3>

# </div>

# <script>

# function diagnose()
# {
#     let score = 0;

#     if(document.getElementById("fever").checked)
#     {
#         score += 3;
#     }

#     if(document.getElementById("cough").checked)
#     {
#         score += 2;
#     }

#     if(document.getElementById("headache").checked)
#     {
#         score += 1;
#     }

#     if(document.getElementById("fatigue").checked)
#     {
#         score += 2;
#     }

#     if(document.getElementById("breathing").checked)
#     {
#         score += 3;
#     }

#     let result = "";

#     if(score >= 8)
#     {
#         result = "High Risk: Possible Severe Infection";
#     }
#     else if(score >= 5)
#     {
#         result = "Moderate Risk: Viral Infection";
#     }
#     else if(score >= 2)
#     {
#         result = "Mild Symptoms: Take Rest";
#     }
#     else
#     {
#         result = "Healthy";
#     }

#     document.getElementById("result").innerHTML = result;
# }

# </script>

# </body>
# </html>


#include<iostream>
# using namespace std;

# void evaluateEmployee()
# {
#     string name;

#     int communication;
#     int teamwork;
#     int punctuality;
#     int productivity;
#     int leadership;

#     cout << "\n=== EMPLOYEE PERFORMANCE EVALUATION SYSTEM ===\n";

#     cout << "\nEnter Employee Name: ";
#     cin >> name;

#     cout << "\nRate Employee From 1 to 10\n";

#     cout << "Communication Skills: ";
#     cin >> communication;

#     cout << "Teamwork: ";
#     cin >> teamwork;

#     cout << "Punctuality: ";
#     cin >> punctuality;

#     cout << "Productivity: ";
#     cin >> productivity;

#     cout << "Leadership: ";
#     cin >> leadership;

#     int total =
#         communication +
#         teamwork +
#         punctuality +
#         productivity +
#         leadership;

#     float average = total / 5.0;

#     cout << "\n----- PERFORMANCE REPORT -----\n";

#     cout << "Employee Name : " << name << endl;
#     cout << "Total Score   : " << total << endl;
#     cout << "Average Score : " << average << endl;

#     if(average >= 8)
#     {
#         cout << "\nPerformance Level : Excellent\n";
#         cout << "Promotion Recommended\n";
#     }
#     else if(average >= 6)
#     {
#         cout << "\nPerformance Level : Good\n";
#         cout << "Increment Recommended\n";
#     }
#     else if(average >= 4)
#     {
#         cout << "\nPerformance Level : Average\n";
#         cout << "Training Recommended\n";
#     }
#     else
#     {
#         cout << "\nPerformance Level : Poor\n";
#         cout << "Needs Serious Improvement\n";
#     }
# }

# int main()
# {
#     int choice;

#     do
#     {
#         cout << "\n========== MENU ==========\n";

#         cout << "1. Evaluate Employee\n";
#         cout << "2. Exit\n";

#         cout << "\nEnter Your Choice: ";
#         cin >> choice;

#         switch(choice)
#         {
#             case 1:
#                 evaluateEmployee();
#                 break;

#             case 2:
#                 cout << "\nExiting Program...\n";
#                 break;

#             default:
#                 cout << "\nInvalid Choice!\n";
#         }

#     } while(choice != 2);

#     return 0;
# }