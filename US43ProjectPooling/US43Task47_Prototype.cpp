#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <forward_list>
#include <ctime>
#include <chrono>
#include <set>

using namespace std::chrono;

// CONSTANT VARIABLE DECLARATION
const int NUM_PROJECTS = 100;
const int NUM_PROJECT_ATTRIBUTES = 5;
const int NUM_SKILLS = 7;
const int NUM_STUDENTS = 500;
const int TEAM_SIZE = 5;
const int NUM_CLASS_SECTIONS = 4;
const int MIN_STUDENT_ID = 1000;
const int MAX_STUDENT_ID = 9999;

/*template <class ForwardIt>
    void quicksort(ForwardIt first, ForwardIt last)
    {
        if(first==last) return;
        auto pivot = *std::next(first, std::distance(first,last)/2);
        ForwardIt middle1 = std::partition(first, last, [pivot](const auto& em){return em < pivot;});
        ForwardIt middle2 = std::partition(middle1, last,
                            [pivot](const auto& em){return !(pivot < em);});
        quicksort(first, middle1);
        quicksort(middle2, last);
}*/

struct Project {
    int id;
    int sponsorID;
    int type; // 0 = Online | 1 = Ground | 2 = Hybrid
    int priority; // 0 = Not Required | 1 = Required
    int* classID;
    int skills[NUM_SKILLS];
    int* teamMembers[TEAM_SIZE];
    int compatibilityRating;
};

struct ClassSection {
    int id;
    int type;
    int minNumProjects;
    std::vector<int> roster();
    std::vector<Project> project();
};

struct Student {
    int id;
    int type;
    int classID;
    int skills();
};

int getRandomInt(int min, int max) {
	int value = rand() % (max-min +1) + min;
	return value;
}

/*int getUniqueInt(int min, int max, int *generatedValues[NUM_STUDENTS]) {
    int value = getRandomInt(min, max);
    for (int i = 0; i < NUM_STUDENTS; i++) {
        while (std::find(*generatedValues, *(generatedValues + NUM_STUDENTS), value) != *(generatedValues + NUM_STUDENTS)) {
            value = getRandomInt(min, max);
        }
        *(generatedValues + i) = value;
    }

    return value;
}*/

/*int getPartitionSize(std::vector<Project> pool, int x)
{
    int partitionSize;

    if (x == 0) {
        partitionSize = count_if(pool.begin(), pool.end(), [](Project p){
        return p.type == 0;
        });
    } else if (x == 1) {
        partitionSize = count_if(pool.begin(), pool.end(), [](Project p){
        return p.type == 1;
        });
    } else if (x == 2) {
        partitionSize = count_if(pool.begin(), pool.end(), [](Project p){
        return p.type == 2;
        });
    };

    return partitionSize;
}

int getPartitionSize(std::vector<ClassSection> pool, int x)
{
    int partitionSize;

    if (x == 0) {
        partitionSize = count_if(pool.begin(), pool.end(), [](ClassSection c){
        return c.type == 0;
        });
    } else if (x == 1) {
        partitionSize = count_if(pool.begin(), pool.end(), [](ClassSection c){
        return c.type == 1;
        });
    };

    return partitionSize;
}

int getPartitionSize(std::vector<Student> pool, int x)
{
    int partitionSize;

    if (x == 0) {
        partitionSize = count_if(pool.begin(), pool.end(), [](Student s){
        return s.type == 0;
        });
    } else if (x == 1) {
        partitionSize = count_if(pool.begin(), pool.end(), [](Student s){
        return s.type == 1;
        });
    };

    return partitionSize;
}

ClassSection[NUM_CLASS_SECTIONS] generateClassSectionPool()
{
    ClassSection pool[NUM_CLASS_SECTIONS];
    ClassSection classSection;

    for (int i = 0; i < NUM_CLASS_SECTIONS; i++)
    {
        classSection.id = i + 1; // Sequentially assigns Class Section ID
        classSection.type = getRandomInt(0, 1); // Class Sections can only be Online-0 or Ground-1

        pool[i] = classSection;
    }

    return pool;
}

Project[NUM_PROJECTS] generateProjectPool()
{
    Project pool[NUM_PROJECTS];
    Project project;

    for (int i = 0; i < NUM_PROJECTS; i++)
    {
        project.id = i + 1; // Sequentially assigns Project ID
        project.sponsorID = getRandomInt(1, (NUM_PROJECTS + 1);
        project.type = getRandomInt(0, 2);
        project.priority = getRandomInt(0, 1);

        pool[i] = project;
    }

    return pool;
}

Student[NUM_STUDENTS] generateStudentPool()
{
    Student pool[NUM_STUDENTS];
    Student student;

    int min = MIN_STUDENT_ID;
    int max = MAX_STUDENT_ID;
    int generatedValues[NUM_STUDENTS];
    int value = getRandomInt(min, max);

    for (int i = 0; i < NUM_STUDENTS; i++) {
        while (std::find(generatedValues[0], generatedValues[NUM_STUDENTS]), value)
        != generatedValues[NUM_STUDENTS]) {
            value = getRandomInt(min, max);
        }
        student.id = value;
        student.type = getRandomInt(0, 1); // Students can only be Online (0) or Ground (1)
        pool[i] = student;
    }

    delete[] generatedValues;

    return pool;
}*/

int main()
{
    auto start = high_resolution_clock::now();

    int numOnlineProjects = 0;
    int numGroundProjects = 0;
    int numHybridProjects = 0;
    int numOnlineStudents = 0;
    int numGroundStudents = 0;
    int numOnlineClassSections = 0;
    int numGroundClassSections = 0;

    // INITIALIZE PROJECT POOLS
    Project projectPool[NUM_PROJECTS];
    Project project;

    for (int i = 0; i < NUM_PROJECTS; i++)
    {
        project.id = i + 1; // Sequentially assigns Project ID
        project.sponsorID = getRandomInt(1, (NUM_PROJECTS + 1));
        project.type = getRandomInt(0, 2);
        project.priority = getRandomInt(0, 1);

        projectPool[i] = project;
    }

    // INITIALIZE STUDENT POOL
    Student studentPool[NUM_STUDENTS];
    Student student;

    int min = MIN_STUDENT_ID;
    int max = MAX_STUDENT_ID;
    std::vector<int> generatedValues(NUM_STUDENTS);
    int value = getRandomInt(min, max);

    for (int i = 0; i < NUM_STUDENTS; i++) {
        while (std::find(generatedValues.begin(), generatedValues.end(), value)
        != generatedValues.end()) {
            value = getRandomInt(min, max);
        }
        generatedValues.push_back(value);
        student.id = value;
        student.type = getRandomInt(0, 2);
        studentPool[i] = student;
    }

    // INITIALIZE CLASS SECTION POOL
    ClassSection classSectionPool[NUM_CLASS_SECTIONS];
    ClassSection classSection;

    for (int i = 0; i < NUM_CLASS_SECTIONS; i++)
    {
        classSection.id = i + 1; // Sequentially assigns Class Section ID
        classSection.type = getRandomInt(0, 1); // Class Sections can only be Online-0 or Ground-1

        classSectionPool[i] = classSection;
    }

    std::cout << "Begin Project Partition 0 (Initial Pooling of Projects)" << std::endl;
    std::cout << "Project ID" << " ";
    std::cout << "Sponsor ID" << " ";
    std::cout << "Type" << " ";
    std::cout << "Priority" << " ";
    std::cout << std::endl;

    for (int i = 0; i < NUM_PROJECTS; i++)
    {
        std::cout << projectPool[i].id << "   ";
        std::cout << projectPool[i].sponsorID << "   ";
        std::cout << projectPool[i].type << "   ";
        std::cout << projectPool[i].priority << "   ";
        std::cout << std::endl;
    }

    std::cout << "Begin Student Partition 0 (Initial Pooling of Projects)" << std::endl;
    std::cout << "Student ID" << " ";
    std::cout << "Type" << " ";
    std::cout << std::endl;

    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        std::cout << studentPool[i].id << "   ";
        std::cout << studentPool[i].type << "   ";
        std::cout << std::endl;
    }

    std::cout << "Begin Class Section Partition 0 (Initial Pooling of Projects)" << std::endl;
    std::cout << "Class Section ID" << " ";
    std::cout << "Type" << " ";
    std::cout << "Mininum Number of Projects" << " ";
    std::cout << std::endl;

    for (int i = 0; i < NUM_CLASS_SECTIONS; i++)
    {
        std::cout << classSectionPool[i].id << "   ";
        std::cout << classSectionPool[i].type << "   ";
        std::cout << std::endl;
    }

    // Project Partition 1 separates out Online projects
    /*auto projectPartition1 = std::partition(projectPool.begin(), projectPool.end(), [](Project p){
        return p.type == 0;
    });

    // Project Partition 2 separates out Ground projects
    auto projectPartition2 = std::partition(projectPartition1, projectPool.end(), [](Project p){
        return p.type == 1;
    });

    numOnlineProjects = getPartitionSize(projectPool, 0);
    numGroundProjects = getPartitionSize(projectPool, 1);
    numHybridProjects = getPartitionSize(projectPool, 2);

    std::cout << "Num Online Projects: " << numOnlineProjects << std::endl;
    std::cout << "Num Ground Projects: " << numGroundProjects << std::endl;
    std::cout << "Num Hybrid Projects: " << numHybridProjects << std::endl;

    std::cout << "Begin partitioned Project Pool:" << std::endl;

    for (int i = 0; i < NUM_PROJECTS; i++)
    {
        std::cout << projectPool[i].id << " ";
        std::cout << projectPool[i].sponsorID << " ";
        std::cout << projectPool[i].type << " ";
        std::cout << projectPool[i].priority << " ";
        std::cout << std::endl;
    }

    // Student Partition 1 separates out Online students
    auto studentPartition1 = std::partition(studentPool.begin(),
    studentPool.end(), [](Student s){
        return s.type == 0;
    });

    // Student Partition 2 separates out Ground students
    auto studentPartition2 = std::partition(studentPool.begin(),
    studentPool.end(), [](Student s){
        return s.type == 1;
    });

    numOnlineStudents = getPartitionSize(studentPool, 0);
    numGroundStudents = getPartitionSize(studentPool, 1);

    std::cout << "Num Online Students: " << numOnlineStudents << std::endl;
    std::cout << "Num Ground Students: " << numGroundStudents << std::endl;

    std::cout << "Begin partitioned Class Section Pool:" << std::endl;

    for (int i = 0; i < NUM_CLASS_SECTIONS; i++)
    {
        std::cout << classSectionPool[i].id << " ";
        std::cout << classSectionPool[i].type << " ";
        std::cout << std::endl;
    }

    // Class Section Partition 1 separates out Online class sections
    auto classSectionPartition1 = std::partition(classSectionPool.begin(),
    classSectionPool.end(), [](ClassSection c){
        return c.type == 0;
    });

    // Class Section Partition 2 separates out Ground class sections
    auto classSectionPartition2 = std::partition(classSectionPool.begin(),
    classSectionPool.end(), [](ClassSection c){
        return c.type == 1;
    });

    numOnlineClassSections = getPartitionSize(classSectionPool, 0);
    numGroundClassSections = getPartitionSize(classSectionPool, 1);

    std::cout << "Num Online Class Sections: " << numOnlineClassSections << std::endl;
    std::cout << "Num Ground Class Sections: " << numGroundClassSections << std::endl;

    std::cout << "Begin partitioned Class Section Pool:" << std::endl;

    for (int i = 0; i < NUM_CLASS_SECTIONS; i++)
    {
        std::cout << classSectionPool[i].id << " ";
        std::cout << classSectionPool[i].type << " ";
        std::cout << std::endl;
    }

    int j = 0;
    int k = 0;

    for (int i = 0; i < numOnlineProjects; i++) {
        if (j >= numOnlineClassSections) {
            j = 0;
        }
        projectPool[i].classID = classSectionPool[j].id;
        j++;
    }

    j = numOnlineClassSections;

    for (int i = numOnlineProjects; i < numGroundProjects; i++) {
        if (j >= numGroundClassSections) {
            j = numOnlineClassSections;
        }
        projectPool[i].classID = classSectionPool[j].id;
        j++;
    }

    for (int i = 0; i < NUM_PROJECTS; i++)
    {
        std::cout << projectPool[i].id << " ";
        std::cout << projectPool[i].type << " ";
        std::cout << projectPool[i].classID << " ";
        std::cout << std::endl;
    }*/

    return 0;
}
