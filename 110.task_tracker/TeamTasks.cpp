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

  		for (int i = 0; i < task_count; i++){
  			if (untouched_tasks[TaskStatus::NEW] > 0){
  				untouched_tasks[TaskStatus::NEW]--;
  				updated_tasks[TaskStatus::IN_PROGRESS]++;
  				task_by_person[person][TaskStatus::NEW]--;
  				task_by_person[person][TaskStatus::IN_PROGRESS]++;
  			} else {
  				if (untouched_tasks[TaskStatus::IN_PROGRESS] > 0){
  					untouched_tasks[TaskStatus::IN_PROGRESS]--;
  					updated_tasks[TaskStatus::TESTING]++;
  	  				task_by_person[person][TaskStatus::IN_PROGRESS]--;
  	  				task_by_person[person][TaskStatus::TESTING]++;
  				} else {
  	  				if (untouched_tasks[TaskStatus::TESTING] > 0){
  	  					untouched_tasks[TaskStatus::TESTING]--;
  	  					updated_tasks[TaskStatus::DONE]++;
  	  	  				task_by_person[person][TaskStatus::TESTING]--;
  	  	  				task_by_person[person][TaskStatus::DONE]++;
  	  				}
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
