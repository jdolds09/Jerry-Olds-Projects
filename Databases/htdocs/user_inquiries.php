<!DOCTYPE html>
<html>
	<head>
		<style>
			.answer:visited
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
                margin-left: 5px;
				margin-right: 10px;
			}
            input[type = "text"]
            {
                width: 80px;
                margin-right: 10px;
                margin-left: 5px;
                margin-bottom: 15px;
            }
		</style>
		<meta charset="utf-8">
		<meta name= "viewport" content="width=device-width">
		<meta name= "descriptions" content="User friendly online animal shelter">
		<meta name= "keywords" content="animal, shelter, animal shelter, dogs, cats, adoption, donation, pets">
		<meta name= "author" content="Donovan Almendariz, Jerry Olds">
		<title>Animal Shelter | Inquiries</title>
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

		<h1 align = "center">INQUIRIES</h1>

            <?php
			// Filters
				session_start();
				echo '<div class = "center">';
					echo '<form method="post" action="">';
					// Date filter
						echo '<font>Date:</font>';
						echo '<input type = "text" name = "date" value = "' . $_SESSION['inquiry_date'] . '"/>';
					// Animal name filter
						echo '<font>Animal Name:</font>';
						echo '<input type = "text" name = "a_name" value = "' . $_SESSION['inquiry_a_name'] . '"/>';
					// Submit button
						echo '<input type = "submit" name = "submit" class = button value = "GO"/>';
					echo '</form>';
				echo '</div>';

			// Clear animal filter variables
				session_start();
				$_SESSION['type'] = "";
				$_SESSION['size'] = "";
				$_SESSION['age'] = "";
				$_SESSION['date'] = "";
				$_SESSION['first_name'] = "";
				$_SESSION['last_name'] = "";
				$_SESSION['a_name'] = "";
				$_SESSION['transaction_type'] = "";
				$_SESSION['transaction_name'] = "";
				$_SESSION['inquiry_first_name'] = "";
				$_SESSION['inquiry_last_name'] = "";
				
            // Connect to database
                include('connection.php');
            
			// Get active user id
                $profile_id = $_SESSION['active_user_id'];
			
			// Display inquiries
				include('user_inquiries_filters.php');

				if(isset($_POST['submit']) && !empty($_POST['submit']))
				{
					$_SESSION['inquiry_date'] = $_POST['date'];
					$_SESSION['inquiry_a_name'] = $_POST['a_name'];
	
				// Re-direct to admin_inquiries page
					header('Location: user_inquiries.php');
				}
				
            ?>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

	</body>
</html>
