import json


class Database:
    def __init__(self, path: str):
        self.path = path

    # Чтение данных
    def get_data(self, path: str = None) -> 'Database':
        with open(path if path else self.path, 'r', encoding = 'utf-8') as json_file:
            self.data = json.load(json_file)
        return self

    # Сохранение данных
    def save_data(self, path: str = None) -> 'Database':
        with open(path if path else self.path, 'w', encoding = 'utf-8') as json_file:
            json.dump(self.data, json_file, indent = 4)
        return self

    # Поиск данных
    def search_by_fields_and_values(self, criteria: dict) -> dict:
        for index, object in enumerate(self.data):
            if all(object[key] == criteria[key] for key in criteria.keys()):
                return self.data[index]

    # Обновление данных
    def update_objects(self, old_values: dict, new_values: dict) -> 'Database':
        for index, values in enumerate(self.data):
            if all(values[key] == old_values[key] for key in old_values.keys()):
                new_values['country_id'] = values['country_id']
                self.data[index].update(new_values)
        return self

    # Добавление данных
    def add_data(self, *objects: dict) -> 'Database':
        for object in objects:
            object['country_id'] = int(self.data[-1]['country_id']) + 1
            object = dict(sorted(object.items(), key = lambda pair: pair[0]))
            self.data.append(object)

        return self

    def __str__(self):
        return ', '.join(str(object) for object in self.data)
