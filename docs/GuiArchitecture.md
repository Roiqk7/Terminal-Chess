# GUI Architecture Overview

## Scene

- A **Scene** is a collection of lines that are rendered independently.
        - Each line spans `GUI::width` characters, with a total of `GUI::height` lines per scene.
        - In scenes requiring user input, the number of lines is reduced to accommodate the input area.
        - Scenes are containers for elements but do not manage their lifecycle or interactions.
- Scenes are categorized into raw and processed types:
        - **Raw scenes** need to be formatted in order to be rendered.
        - **Processed scenes** have been formatted and are ready for rendering.
- Scenes are static in nature; they do not handle user interactions directly. That is left to the rest of the program.
- It's assumed that scene switching is infrequent, eliminating the need for active scene management or some form of scene stack.

## Element

- **Elements** are the fundamental components of the GUI, representing individual pieces of content or functionality.
- An Element's responsibility is limited to storing its own metadata, which includes information necessary for formatting and rendering.
        - This metadata includes if the element is necessary for the scene. If not then in **can be skipped** during rendering if the user's terminal is too small.
- Elements do not provide the structural information required by the Formatter to arrange them within a scene. That task is left to the Scene itself. (It depends on the order in which elements are added to the scene.)

## Formatter

- The **Formatter** plays a critical role in the GUI architecture. Its primary function is to arrange elements within a scene according to specific layout rules.
        - It ensures that each scene adheres to the dimensions specified by `GUI::width` and `GUI::height`, adjusting for scenes that incorporate user input fields.
- The Formatter's task is to translate raw scenes into processed scenes, ready for rendering.
- The Formatter **assumes** that the first element in the Scene is at the top and the last is at the bottom. It **does not** handle the reordering of elements within a scene.
- The Formatter will add equal number of empty lines in between elements to ensure that the scene is filled up to `GUI::height`.
- The Formatter **will center** all elements in the scene.

## Renderer

- The **Renderer** is tasked with displaying scenes to the user.
        - It accepts processed scenes and visually renders them, ensuring that the GUI's content is presented on the screen.
- The Renderer acts as the bridge between the GUI's internal representation and its visual output, bringing formatted scenes to life.