class CommonCharacterRemoval:
    def __init__(self, first_str, second_str):
        self.first_string = first_str
        self.second_string = second_str

    def get_common_character(self):
        unique_chars_of_first = set(self.first_string)
        unique_chars_of_second = set(self.second_string)
        common_characters = set()
        for char in unique_chars_of_first:
            if char in unique_chars_of_second:
                common_characters.add(char)
        return common_characters

    def remove_common_character(self):
        common_chars = self.get_common_character()
        new_first_string, new_second_string = "", ""
        for char in self.first_tring:
            if char not in common_chars:
                new_first_string += char

        for char in self.second_tring:
            if char not in common_chars:
                new_second_string += char
        self.first_string = new_first_string
        self.second_string = new_second_string

    def get_merged_string(self):
        merged_string = ""
        self.remove_common_character()
        for char in self.first_string:
            merged_string += char
        for char in self.second_string:
            merged_string += char
        return merged_string

    def get_first_string(self):
        return self.first_string

    def get_second_string(self):
        return self.second_string


if __name__ == '__main__':
    # Test get_common_character

    first_string = input()
    second_string = input()
    print(CommonCharacterRemoval(first_string, second_string).get_merged_string())
