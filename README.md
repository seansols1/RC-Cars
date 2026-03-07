# RC-Cars
Members:
Fernando Vela,
Sean Solis

For our project, we're developing an RC car to be controlled using a smartphone as the remote. In order to do this we need to build the RC car ourselves, and code the controls using HTML, CSS, and Javascript in VS Code. We connect the phone and the RC car with Esp32; it has its own wifi and and network. The code will be in VS code first then transorted to Esp32 where people can connect with it and control the RC car. The control layout will consist of left and right arrow buttons, a disconnect button and a braking system. It will also show you when you're connected to the RC car.

![IMG_0376](https://github.com/user-attachments/assets/13169ceb-5cd9-45f6-a78d-f0438e302c84)

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title> </title>
    <link rel="stylesheet" href="/Style.css">
</head>
<body>
<div class="Controls"> 

    
    <button class="Forward "> ↑ </button>
    <button class="backwards"> ↓ </button>
    <button class="right"> → </button>
    <button class="left"> ← </button>
    <button class="disconnect "> disconnect </button>
    <button class="connected "> </button>
    <button class="break">  break </button>
    
   

</div>


    
</body>
</html>
