#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>


using namespace std;


// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

TaskStatus Next(TaskStatus task_status) {
	return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const{
		return task_by_person.at(person);
	}

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  	void AddNewTask(const string& person){
  		task_by_person[person][TaskStatus::NEW]++;
  	}

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
  		map<TaskStatus, int> updated_tasks;
  		map<TaskStatus, int> untouched_tasks = task_by_person[person];
  		TaskStatus current_status = TaskStatus::NEW;
  		TaskStatus next_status = TaskStatus::IN_PROGRESS;
  		for (int i = 0; i < task_count; i++){
  			if (untouched_tasks[current_status] > 0){
  				untouched_tasks[current_status]--;
  				updated_tasks[next_status]++;
  				task_by_person[person][current_status]--;
  				task_by_person[person][next_status]++;
  			} else {
  				if (Next(next_status) != TaskStatus::DONE){
  					current_status = next_status;
  					next_status = Next(next_status);
  				}
  			}
  		}


  		remove_empty_elements(untouched_tasks);
  		remove_empty_elements(task_by_person[person]);
  		untouched_tasks.erase(TaskStatus::DONE);
  		return {updated_tasks, untouched_tasks};
  	}

private:
  	map<string, TasksInfo> task_by_person;
  	void remove_empty_elements(TasksInfo& task_info){
  		auto iterating_map = task_info;
  		for (auto& [key, value]:iterating_map){
  			if ( value == 0){
  				task_info.erase(key);
  			}
  		}
  	}
};



void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}


int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}
