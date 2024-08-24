Cat and Mouse Game Project

Author: Selemon Neguse (ID: 324734433)

General Overview:

The project revolves around simulating a game scenario featuring a cat and a mouse. 
The primary goal is for the mouse to consume all the cheeses strategically while avoiding capture by the cats. 
Cats have the opportunity to catch the mouse up to three times. Additional game elements, 
such as keys for opening doors and gifts for earning points, enhance the overall gameplay experience.

Created Files:

- **Controller.h/cpp:** Likely responsible for managing the game's flow and handling interactions 
						between various game objects.
- **GameObject.h/cpp:** Represents the properties of different game objects.
- **MovingObject.h:** Manages the movement of objects within the game.
- **StaticObject.h:** Represents static game objects.
- **Menu.h/cpp:** Handles game menus and user interface elements.
- **Resources.h/cpp:** Manages loading and handling game resources like textures and sounds.
- **Board.h/cpp:** Manages the game board and its components.
- **Window.h/cpp:** Represents the game window and manages rendering.
- **Cat.h/cpp:** Represents the cat character and defines its behavior.
- **Mouse.h/cpp:** Represents the mouse character and its behavior.
- **Cheese.h/cpp:** Represents cheese objects within the game.
- **Wall.h/cpp:** Represents wall objects that obstruct movement.
- **Gift.h/cpp:** Represents gift objects that offer benefits to the player.
- **Key.h/cpp:** Represents key objects used to unlock doors.
- **Door.h/cpp:** Represents door objects that can be opened with keys.
- **Location.h:** Defines a location structure for object positioning.

Data Structures:

- **Vector:** Used for managing collections of objects.
- **String:** Used for storing textual data.
- **Class:** Utilized for encapsulating related data and functions.
- **Struct:** Used for location of the objects. 

Algorithms:

Cats pursue the mouse by moving vertically to align with the mouse's position and then giving chase.

Design:

The central class, likely the `Controller`, takes on the responsibility of managing the game's lifecycle and
orchestrating interactions between different components. Each class appears to have a specific role, 
handling aspects such as object behavior, rendering, or game logic.