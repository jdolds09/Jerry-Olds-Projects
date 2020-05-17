<!DOCTYPE html>
<html>
	<head>
		<style>
			.name:visited
			{
				color: blue;
			}
			.center
			{
				text-align: center;
				margin-bottom: 10px;
			}
			select
			{
				margin-right: 10px;
			}
			
		</style>
		<meta charset="utf-8">
		<meta name= "viewport" content="width=device-width">
		<meta name= "descriptions" content="User friendly online animal shelter">
		<meta name= "keywords" content="animal, shelter, animal shelter, dogs, cats, adoption, donation, pets">
		<meta name= "author" content="Donovan Almendariz, Jerry Olds">
		<title>Animal Shelter | Animals</title>
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

	<!--Title-->
		<h1 align = "center">ANIMALS</h1>

	<!--Filters-->
		<?php session_start(); ?>
		<div class = "center">
			<form method="post" action="">
			<!--Animal type filter-->
				<font>Type:</font>
				<select name ="type">
					<?php echo '<option value = "' . $_SESSION['type'] . '">' . $_SESSION['type'] . '</option>';?>
					<option value = ""></option>
					<option value = "Dog">Dog</option>
					<option value = "Cat">Cat</option>
					<option value = "Bird">Bird</option>
					<option value = "Reptile">Reptile</option>
				</select>
			<!--Animal size filter-->
				<font>Size:</font>
				<select name ="size">
					<?php echo '<option value = "' . $_SESSION['size'] . '">' . $_SESSION['size'] . '</option>';?>
					<option value = ""></option>
					<option value = "Small">Small</option>
					<option value = "Medium">Medium</option>
					<option value = "Large">Large</option>
				</select>
			<!--Animal size filter-->
				<font>Age:</font>
				<select name ="age">
					<?php echo '<option value = "' . $_SESSION['age'] . '">' . $_SESSION['age'] . '</option>';?>
					<option value = ""></option>
					<option value = "1">1</option>
					<option value = "2">2</option>
					<option value = "3">3</option>
					<option value = "4">4</option>
					<option value = "5+">5+</option>
				</select>
			<!--Submit button-->
				<input type = "submit" name = "submit" class = button value = "GO"/>
			</form>
		</div>

		<?php
		// Connect to database
			include('connection.php');

		// Clear transaction filter variables
			$_SESSION['date'] = "";
			$_SESSION['first_name'] = "";
			$_SESSION['last_name'] = "";
			$_SESSION['a_name'] = "";
			$_SESSION['transaction_type'] = "";
			$_SESSION['transaction_name'] = "";
			$_SESSION['inquiry_date'] = "";
			$_SESSION['inquiry_first_name'] = "";
			$_SESSION['inquiry_last_name'] = "";
			$_SESSION['inquiry_a_name'] = "";

		// Variables
			$result = mysqli_query($con, "SELECT * from animal");
			$type = $_SESSION['type'];
			$size = $_SESSION['size'];
			$age = $_SESSION['age'];
			$i = 1;
			$j = 0;

		// Display animals
			foreach(glob("pictures/*.*") as $picture)
			{
			// Check to see if animal is available before displaying
				$row = $result->fetch_assoc();
				$available = $row['Availability'];
			
			// If all filter options are used
				if($type != "" && $size != "" && $age != "")
				{
				// If age filter option 5+ is chosen
					if($age == "5+")
					{
						if($row['Type'] == $type && $row['Size'] == $size && $row['Age'] >= 5 && $available == 1)
						{
							$j++;
							echo '<ul>';
						// Display picture
							echo '<li><a href = "?link=' . $i . '">';
							echo '<img src ="' . $picture . '" width = "150" height = "150">';
							echo '</a></li>';
						// Display name
							echo '<li><a class = "name" href = "?link2=' . $i . '">' . $row['Name'] . '</a></li>';
						}
					}
				
				// If all filter options are chosen and the age filter option is not 5+
					else
					{
						if($row['Type'] == $type && $row['Size'] == $size && $row['Age'] == $age && $available == 1)
						{
							$j++;
							echo '<ul>';
						// Display picture
							echo '<li><a href = "?link=' . $i . '">';
							echo '<img src ="' . $picture . '" width = "150" height = "150">';
							echo '</a></li>';
						// Display name
							echo '<li><a class = "name" href = "?link2=' . $i . '">' . $row['Name'] . '</a></li>';
						}
					}
				}

			// If filter option type and size are used
				else if($type != "" && $size != "")
				{
					if($row['Type'] == $type && $row['Size'] == $size && $available == 1)
					{
						$j++;
						echo '<ul>';
					// Display picture
						echo '<li><a href = "?link=' . $i . '">';
						echo '<img src ="' . $picture . '" width = "150" height = "150">';
						echo '</a></li>';
					// Display name
						echo '<li><a class = "name" href = "?link2=' . $i . '">' . $row['Name'] . '</a></li>';
					}
				}

			// If filter options type and age are used
				else if($type != "" && $age != "")
				{
				// If age filter option 5+ is chosen
					if($age == "5+")
					{
						if($row['Type'] == $type && $row['Age'] >= 5 && $available == 1)
						{
							$j++;
							echo '<ul>';
						// Display picture
							echo '<li><a href = "?link=' . $i . '">';
							echo '<img src ="' . $picture . '" width = "150" height = "150">';
							echo '</a></li>';
						// Display name
							echo '<li><a class = "name" href = "?link2=' . $i . '">' . $row['Name'] . '</a></li>';
						}
					}
				
				// If filter options type and age are used and age filter option is not 5+
					else
					{
						if($row['Type'] == $type && $row['Age'] == $age && $available == 1)
						{
							$j++;
							echo '<ul>';
						// Display picture
							echo '<li><a href = "?link=' . $i . '">';
							echo '<img src ="' . $picture . '" width = "150" height = "150">';
							echo '</a></li>';
						// Display name
							echo '<li><a class = "name" href = "?link2=' . $i . '">' . $row['Name'] . '</a></li>';
						}
					}
				}

			// If filter options size and age are used
				else if($size != "" && $age != "")
				{
				// If age filter option 5+ is chosen
					if ($age == "5+")
					{
						if($row['Size'] == $size && $row['Age'] >= 5 && $available == 1)
						{
							$j++;
							echo '<ul>';
						// Display picture
							echo '<li><a href = "?link=' . $i . '">';
							echo '<img src ="' . $picture . '" width = "150" height = "150">';
							echo '</a></li>';
						// Display name
							echo '<li><a class = "name" href = "?link2=' . $i . '">' . $row['Name'] . '</a></li>';
						}
					}

				// If filter options size and age are used and age filter option 5+ is not chosen
					else
					{
						if($row['Size'] == $size && $row['Age'] == $age && $available == 1)
						{
							$j++;
							echo '<ul>';
						// Display picture
							echo '<li><a href = "?link=' . $i . '">';
							echo '<img src ="' . $picture . '" width = "150" height = "150">';
							echo '</a></li>';
						// Display name
							echo '<li><a class = "name" href = "?link2=' . $i . '">' . $row['Name'] . '</a></li>';
						}
					}
				}

			// If type filter option is chosen
				else if($type != "")
				{
					if($row['Type'] == $type && $available == 1)
					{
						$j++;
						echo '<ul>';
					// Display picture
						echo '<li><a href = "?link=' . $i . '">';
						echo '<img src ="' . $picture . '" width = "150" height = "150">';
						echo '</a></li>';
					// Display name
						echo '<li><a class = "name" href = "?link2=' . $i . '">' . $row['Name'] . '</a></li>';
					}
				}

			// If size filter option is chosen
				else if($size != "")
				{
					if($row['Size'] == $size && $available == 1)
					{
						$j++;
						echo '<ul>';
					// Display picture
						echo '<li><a href = "?link=' . $i . '">';
						echo '<img src ="' . $picture . '" width = "150" height = "150">';
						echo '</a></li>';
					// Display name
						echo '<li><a class = "name" href = "?link2=' . $i . '">' . $row['Name'] . '</a></li>';
					}
				}

			// If age filter option is chosen
				else if($age != "")
				{
				// If age filter option 5+ is chosen
					if($age == "5+")
					{
						if($row['Age'] >= 5 && $available == 1)
						{
							$j++;
							echo '<ul>';
						// Display picture
							echo '<li><a href = "?link=' . $i . '">';
							echo '<img src ="' . $picture . '" width = "150" height = "150">';
							echo '</a></li>';
						// Display name
							echo '<li><a class = "name" href = "?link2=' . $i . '">' . $row['Name'] . '</a></li>';
						}
					}
					
				// If age filter option 5+ is not chosen
					else
					{
						if($row['Age'] == $age && $available == 1)
						{
							$j++;
							echo '<ul>';
						// Display picture
							echo '<li><a href = "?link=' . $i . '">';
							echo '<img src ="' . $picture . '" width = "150" height = "150">';
							echo '</a></li>';
						// Display name
							echo '<li><a class = "name" href = "?link2=' . $i . '">' . $row['Name'] . '</a></li>';
						}
					}
				}

			// If no filter options are chosen
				else
				{
				// Only display animal if it is available
					if($available == 1)
					{
						$j++;
						echo '<ul>';
					// Display picture
						echo '<li><a href = "?link=' . $i . '">';
						echo '<img src ="' . $picture . '" width = "150" height = "150">';
						echo '</a></li>';
					// Display name
						echo '<li><a class = "name" href = "?link2=' . $i . '">' . $row['Name'] . '</a></li>';
					}
					echo '</ul>';
				}
				$i++;
			}

		// If no animals were displayed
			if($j == 0)
				echo '<h2 align = "center">No animals available for given search.</h2>';

		// If filter is used
			if(isset($_POST['submit']) && !empty($_POST['submit']))
			{
				$_SESSION['type'] = $_POST['type'];
				$_SESSION['size'] = $_POST['size'];
				$_SESSION['age'] = $_POST['age'];
				header('Location: animals.php');
			}
		
		// If picture is clicked
			if(isset($_GET['link']))
			{
				session_start();
				$_SESSION['animal_id'] = $_GET['link'];
				mysqli_close($con);
				header('Location: animal.php');
			}
		// If animal name is clicked
			else if(isset($_GET['link2']))
			{
				session_start();
				$_SESSION['animal_id'] = $_GET['link2'];
				mysqli_close($con);
				header('Location: animal.php');
			}
		?>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

	</body>
</html>
