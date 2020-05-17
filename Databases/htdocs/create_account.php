<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<meta name= "viewport" content="width=device-width">
		<meta name= "descriptions" content="User friendly online animal shelter">
		<meta name= "keywords" content="animal, shelter, animal shelter, dogs, cats, adoption, donation, pets">
		<meta name= "author" content="Donovan Almendariz, Jerry Olds">
		<title>Animal Shelter | Create account</title>
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
						<li><a href= "index.php">Home</a></li>
						<li><a href= "about.php">About</a></li>
						<li><a href= "login.php">Sign In</a></li>
					</ul>
				</nav>
			</div>
		</header>

		<section id= "Create">
			<div class="container">
				<div class="dark">
					<form method = "post" action = "">
					
						<h1>Create Account</h1>

						<div class="form-input">
							<input type="text" name = "fname" placeholder="First Name"/>	
						</div>

						<div class="form-input">
							<input type="text" name = "lname" placeholder="Last Name"/>	
						</div>

						<div class="form-input">
							<input type="text" name = "username" placeholder="Username"/>	
						</div>

						<div class="form-input">
							<input type="email" name = "email" placeholder="Email"/>	
						</div>

						<div class="form-input">
							<input type="text" name = "phone_number" placeholder="Phone Number"/>	
						</div>

						<div class="form-input">
							<input type="password" name = "pwd" placeholder="Password"/>
						</div>

						<input type="submit" name="submit" class = "button_1" value = "CREATE ACCOUNT"/>

						<nav id= "create">
							<button type = "submit" class= "button_2"><a href= "login.php" style="color:white">Already Have An Account? Sign In!</a></button>
						</nav>

					</form>
				</div>
			</div>	
		</section>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

<!--Sending new profile data to database-->
<?php
// TODO(optional): Add some sort of input validation if we have the time
	if(isset($_POST['submit']) && !empty($_POST['submit']))
	{
	// Variables
		$first_name = $_POST['fname'];
		$last_name = $_POST['lname'];
		$phone_number = $_POST['phone_number'];
		$email = $_POST['email'];
		$username = $_POST['username'];
		$pwd = $_POST['pwd'];
				
	// Connect to database
		include('connection.php');

	// Insert new profile in to database
		$sql = "INSERT INTO profile (First_Name, Last_Name, Mobile_Number, Email, Username, Pwd, Join_Date) 
				VALUES  ('$first_name', '$last_name', '$phone_number', '$email', '$username', '$pwd', NOW())";
	
	// Unsuccessful entry in to database
		if(!mysqli_query($con, $sql))
			header('Location: error.php');

	// Successful entry in to database
		else
		{
		// Set active user
			session_start();
			$result = mysqli_query($con, "SELECT PROFILE_ID FROM profile WHERE Username = '$username'");
			$row = $result->fetch_assoc();
			$_SESSION['active_user_id'] = $row['PROFILE_ID']; 
		// Disconnect from database
			mysqli_close($con);
		// Re-direct to home page
			header('Location: user_home.php');
		}
	}
?>

	</body>
</html>