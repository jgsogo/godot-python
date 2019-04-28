
class Mancala:
    def __init__(self):
        print("(python) Mancala::init")
        self.state = 0

    def get_state(self):
        print("(python) Mancala::get_state")
        self.state += 1
        return "(python) current state: {!r}".format(self.state)

    def play_position(self, value):
        print("(python) Mancala::play_position(value={!r})".format(value))
        self.state = value


# Create a single object to keep state
mancala = Mancala()
