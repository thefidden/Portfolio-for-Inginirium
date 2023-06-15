import json


class JSON_Database:
    def __init__(self, path: str):
        self.path = path

    # Чтение данных
    def get_data(self, path: str = None) -> 'JSON_Database':
        with open(path if path else self.path, 'r', encoding = 'utf-8') as json_file:
            self.data = json.load(json_file)
        return self

    # Сохранение данных
    def save_data(self, path: str = None) -> 'JSON_Database':
        with open(path if path else self.path, 'w', encoding = 'utf-8') as json_file:
            json.dump(self.data, json_file, indent = 4)
        return self

    # Поиск данных
    def search_by_fields_and_values(self, criteria: dict) -> dict:
        for index, object in enumerate(self.data):
            if all(object[key] == criteria[key] for key in criteria.keys()):
                return self.data[index]

    # Обновление данных
    def update_object(self, old_object: dict, new_object: dict) -> 'JSON_Database':
        for index, object in enumerate(self.data):
            if object == old_object:
                new_object['country_id'] = object['country_id']
                self.data[index] = new_object
        return self

    # Добавление данных
    def add_data(self, *objects: dict) -> 'JSON_Database':
        for object in objects:
            object['country_id'] = int(self.data[-1]['country_id']) + 1
            object = dict(sorted(object.items(), key = lambda pair: pair[0]))
            self.data.append(object)

        return self

    def __str__(self):
        return '\n'.join(str(object) for object in self.data)
