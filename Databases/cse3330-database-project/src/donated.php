<!DOCTYPE html>
<html>
	<head>
        <style>
            a {text-decoration: none;}
            a:visited {text-decoration: none;}
            a:hover {text-decoration: none;}
            a:focus {text-decoration: none;}
            a:hover, .a:active {text-decoration: none;}

            img 
            {
                display: block;
                margin-left: auto;
                margin-right: auto;
                margin-bottom: 30px;
            }
            button 
            {
                display: block;
                margin-left: auto;
                margin-right: auto;
            }
        </style>
		<meta charset="utf-8">
		<meta name= "viewport" content="width=device-width">
		<meta name= "descriptions" content="User friendly online animal shelter">
		<meta name= "keywords" content="animal, shelter, animal shelter, dogs, cats, adoption, donation, pets">
		<meta name= "author" content="Donovan Almendariz, Jerry Olds">
		<title>Animal Shelter | Donated</title>
		<link rel="stylesheet" href= "./style.css">
	</head>
	<body>
		<header>
			<div class= "container">
				<div id= "branding">
                <h1><span class= "highlight">DJ's</span> Animal Shelter</h1>
				</div>
				<nav>
					<ul>
                        <li><a href= "user_home.php">Home</a></li>
                        <li><a href = "animals.php">Animals</a></li>
						<li><a href = "user_inquiries.php">Inquiries</a></li>
                        <li><a href = "profile.php">Profile</a></li>
						<li><a href= "about.php">About</a></li>
					<!--Sign Out-->
                        <li><a href= "?sign_out" >Sign Out</a></li>
                        <?php
						// Sign out
                            if(isset($_GET['sign_out']))
                            {
                            // Set active_user to NULL
                                session_start();
                                $_SESSION['active_user_id'] = NULL;
                            // Re-direct to index page
                                header('Location: index.php');
                            }
                        ?>
					</ul>
				</nav>
			</div>
        </header>
        
        <?php
            session_start();
            include('connection.php');
            $animal_id = $_SESSION['animal_id'];
            $result = mysqli_query($con, "SELECT Name from animal WHERE ANIMAL_ID = '$animal_id'");
            $row = $result->fetch_assoc();
            echo '<h1 align = "center">Thank you for donating!</h1>';
            $i = 1;
            foreach(glob("pictures/*.*") as $picture)
			{
			// Display adopted animal picture
                if($i == $animal_id)
                    echo '<img src ="' . $picture . '" width = "300" height = "300">';
                    
				$i++;
            }
            echo '<a href = "user_home.php"><button type = "button" class = "button_1">HOME</button></a>';
        ?>

        <footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

        

    </body>
</html>