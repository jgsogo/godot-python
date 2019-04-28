
class Mancala:
    def __init__(self):
        print("(python) Mancala::init")

    def get_state(self):
        print("(python) Mancala::get_state")
        return "(python) current state"

    def play_position(self, value):
        print("(python) Mancala::play_position(value={!r})".format(value))
