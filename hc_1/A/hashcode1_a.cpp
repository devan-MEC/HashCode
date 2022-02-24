#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct skills
{
    string skill_name;
    int skill_level;
};
typedef struct mentors
{
    string mentor_name;
    int num_skills;
    vector<skills> v;

} mentors;

typedef struct projects
{
    string project_name;
    int project_days;
    int project_score;
    int best_before_day;
    int num_roles;
    vector<skills> v;
} projects;

mentors m[10];
projects p[10];

int main()
{

    int num_mentors, num_projects;
    ifstream input_file("a_an_example.in.txt");
    if (!input_file.is_open())
    {
        cout << "Error opening file\n";
        return EXIT_FAILURE;
    }

    struct skills s_temp;
    input_file >> num_mentors;
    input_file >> num_projects;
    cout << num_mentors << " " << num_projects << endl;

    // acceptin mentors;
    for (int i = 0; i < num_mentors; i++)
    {
        input_file >> m[i].mentor_name;
        input_file >> m[i].num_skills;

        for (int j = 0; j < m[i].num_skills; j++)
        {
            input_file >> s_temp.skill_name;
            input_file >> s_temp.skill_level;
            m[i].v.push_back(s_temp);
        }
    }

    // accepting projects
    for (int i = 0; i < num_projects; i++)
    {
        input_file >> p[i].project_name;
        input_file >> p[i].project_days;
        input_file >> p[i].project_score;
        input_file >> p[i].best_before_day;
        input_file >> p[i].num_roles;
        for (int j = 0; j < p[i].num_roles; j++)
        {
            input_file >> s_temp.skill_name;
            input_file >> s_temp.skill_level;
            p[i].v.push_back(s_temp);
        }
    }

    // test to see if data is stored correctly COMMENT THIS OUT LATER
    // listing mentors
    cout << "MENTOR DETAILS\n";
    for (int i = 0; i < num_mentors; i++)
    {
        cout << "MENTOR DETAILS\n";
        cout << m[i].mentor_name << " " << m[i].num_skills << "\n";

        for (skills s_temp : m[i].v)
        {
            cout << s_temp.skill_name << " " << s_temp.skill_level << endl;
        }
    }
    // listing projects
    cout << "PROJECT DETAILS\n";
    for (int i = 0; i < num_projects; i++)
    {

        cout << p[i].project_name << " " << p[i].project_days << " " << p[i].project_score << " " << p[i].best_before_day << " " << p[i].num_roles << "\n";

        for (skills s_temp : p[i].v)
        {
            cout << s_temp.skill_name << " " << s_temp.skill_level << endl;
        }
    }
    return 0;
}