

// "_Base_1.h" in current directory for previous basic info

#include "_Base_1.h"


int main()
{
    string userType;
    string action;
    doctor doc;
    receptionist rec;
    while (true)
    {
        cout << "Are you a doctor or a receptionist? ";
        cin >> userType;
        cin.ignore();
        switch (userType[0])
        {
        case 'd':
        case 'D':
            doc.enter_details();
            cout << "What would you like to do (e.g. next patient, view patient records)? ";
            cin >> action;
            if (action[0] == 'N' || action[0] == 'n')
            {
                doc.next_patient();
            }
            else
            {
                cout << "Update details ";
                cin >> action;
                if (action[0] == 'y' || action[0] == 'Y')
                {
                    doc.update_own_details();
                }
                else
                {
                    doc.display_own_details();
                }
            }
            // code to handle doctor actions
            break;

        case 'r':
        case 'R':
            cout << "What would you like to do (e.g. patient enter)? Yes | No";
            cin >> action;
            cin.ignore();
            // code to handle receptionist actions
            rec.enter_own_details();
            if (action[0] == 'p' || action[0] == 'P')
            {
                rec.enter_patient();
            }
            else
            {
                rec.view_own_details();
            }
            break;

        default:
            cout << "Invalid input. Please enter either 'doctor' or 'receptionist'." << endl;
            continue;
        }

        // code to handle the user's chosen action
        //about other actions

        // ask the user if they want to perform another action
        cout << "Would you like to perform another action? (y/n) ";
        string response;
        cin >> response;
        cin.ignore();

        if (response[0] != 'y' && response[0] != 'Y')
        {
            break;
        }
    }

    return 0;
}
