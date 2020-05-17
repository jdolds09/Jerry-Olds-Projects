<!DOCTYPE html>
<html>
    <style>
    /* Navbar container */
			.navbar {
			overflow: hidden;
			font-family: Arial;
			}

			/* Links inside the navbar */
			.navbar a {
			float: left;
			font-size: 16px;
			color: white;
			text-align: center;
			text-decoration: none;
			}

			/* The dropdown container */
			.dropdown {
			float: left;
			overflow: hidden;
			}

			/* Dropdown button */
			.dropdown .dropbtn {
			font-size: 16px; 
			border: none;
			outline: none;
			color: white;
			padding: 14px 16px;
			background-color: inherit;
			font-family: inherit; /* Important for vertical align on mobile phones */
			margin: 0; /* Important for vertical align on mobile phones */
			}

			/* Dropdown content (hidden by default) */
			.dropdown-content {
			display: none;
			position: absolute;
			background-color: #f9f9f9;
			min-width: 160px;
			box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);
			z-index: 1;
			}

			/* Links inside the dropdown */
			.dropdown-content a {
			float: none;
			color: black;
			padding: 12px 16px;
			text-decoration: none;
			display: block;
			text-align: left;
			}

			/* Show the dropdown menu on hover */
			.dropdown:hover .dropdown-content {
			display: block;
			}
    </style>
	<head>
		<meta charset="utf-8">
		<meta name= "viewport" content="width=device-width">
		<meta name= "descriptions" content="User friendly online animal shelter">
		<meta name= "keywords" content="animal, shelter, animal shelter, dogs, cats, adoption, donation, pets">
		<meta name= "author" content="Donovan Almendariz, Jerry Olds">
		<title>Animal Shelter | Edit animal</title>
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
						<li><a href= "admin_home.php">Home</a></li>
						<li><a href = "admin_animals.php">Animals</a></li>
                        <li><a href = "add_animal.php">Add Animal</a></li>
						<li><a href = "admin_inquiries.php">Inquiries</a></li>
                        <li><a href = "transactions.php">Transactions</a></li>
                        <li><a href = "adoption_fee.php">Adoption Fee</a></li>
						<li><a href= "about.php">About</a></li>
                        <header>
			<div class= "container">
				<div id= "branding">
					<h1><span class= "highlight">DJ's</span> Animal Shelter</h1>
				</div>
				<nav>
					<ul>
                        
						<div class="navbar">
							<li><a href= "admin_home.php">Home</a></li>
							<li><a href = "admin_animals.php">Animals</a></li>
							<div class="dropdown">
							<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
								<font class="dropbtn">ADMIN ACTIONS <i class="fa fa-caret-down"></i></font>
								<div class="dropdown-content">
									<a href="add_animal.php">ADD ANIMAL</a>
									<a href="admin_inquiries.php">ANSWER INQUIRIES</a>
									<a href="adoption_fee.php">CHANGE ADOPTION FEES</a>
								</div>
							</div>
							<li><a href = "transactions.php">Transactions</a></li>
							<li><a href= "about.php">About</a></li>
							<li><a href= "?sign_out" >Sign Out</a></li>
						</div> 
						
					<!--Sign Out-->
					</ul>
				</nav>
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

		<section id= "Create2">
			<div class="container">
				<div class="dark">
					<form method = "post" action = "">
					
						<h1>Edit Animal</h1>

                        <?php
                        // Connect to database
                            include('connection.php');

                        // Get animal information
                            session_start();
                            $animal_id = $_SESSION['animal_id'];
                            $result = mysqli_query($con, "SELECT Name, Age, Type, Breed, Color, Size, Description FROM animal WHERE ANIMAL_ID = '$animal_id'");
                            $row = $result->fetch_assoc();
                            $name = $row['Name'];
                            $age = $row['Age'];
                            $type = $row['Type'];
                            $breed = $row['Breed'];
                            $color = $row['Color'];
                            $size = $row['Size'];
                            $description = $row['Description'];

                        // Form
                            echo '<div class="form-input">';
                            echo '<input type="text" name = "name" value="' . $name . '"/>';
                            echo '</div>';

                            echo '<div class="form-input">';
                            echo '<input type="number" name = "age" value="' . $age . '"/>';
                            echo '</div>';

                            echo '<div class="form-input">';
                            echo '<input type="text" name = "type" value="' . $type . '"/>';	
                            echo '</div>';

                            echo '<div class="form-input">';
                            echo '<input type="text" name = "breed" value="' . $breed . '"/>';
                            echo '</div>';

                            echo '<div class="form-input">';
                            echo '<input type="text" name = "color" value="' . $color . '"/>';	
                            echo '</div>';
                        
                        // If animal size is Small, have Small the first option
                            if($size == 'Small')
                            {
                                echo '<select name ="size">';
                                echo '<option value = "Small">Small</option>';
                                echo '<option value = "Medium">Medium</option>';
                                echo '<option value = "Large">Large</option>';
                                echo '</select>';
                            }

                        // If animal size is Medium, have Medium the first option
                            if($size == 'Medium')
                            {
                                echo '<select name ="size">';
                                echo '<option value = "Medium">Medium</option>';
                                echo '<option value = "Small">Small</option>';
                                echo '<option value = "Large">Large</option>';
                                echo '</select>';
                            }     
                        
                        // If animal size is Large, have Large the first option
                            if($size == 'Large')
                            {
                                echo '<select name ="size">';
                                echo '<option value = "Large">Large</option>';
                                echo '<option value = "Small">Small</option>';
                                echo '<option value = "Medium">Medium</option>';
                                echo '</select>';
                            }

                        echo '<textarea name = "description" cols = "25" rows = "5">' . $description . '</textarea>';
                        
                        ?>

						<input type="submit" name="submit" class = "button_1" value = "UPDATE"/>

					</form>
				</div>
			</div>	
		</section>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

<!--Sending new animal data to database-->
<?php
	if(isset($_POST['submit']) && !empty($_POST['submit']))
	{
	// Variables
		$name = $_POST['name'];
		$age = $_POST['age'];
		$type = $_POST['type'];
		$breed = $_POST['breed'];
		$color = $_POST['color'];
		$size = $_POST['size'];
		$description = $_POST['description'];
				
	// Connect to database
		include('connection.php');

    // Insert new profile in to database
		$sql = "UPDATE animal SET Name = '$name', Age = '$age', Type = '$type', Breed = '$breed', Color = '$color', Size = '$size', Description = '$description' WHERE ANIMAL_ID = '$animal_id'";
					
		if(!mysqli_query($con, $sql))
			header('Location: error.php');

		else
		{	
		// Disconnect from database
			mysqli_close($con);
		// Re-direct to home page
			header('Location: admin_home.php');
		}
	}
?>

	</body>
</html>