<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<meta name= "viewport" content="width=device-width">
		<meta name= "descriptions" content="User friendly online animal shelter">
		<meta name= "keywords" content="animal, shelter, animal shelter, dogs, cats, adoption, donation, pets">
		<meta name= "author" content="Donovan Almendariz, Jerry Olds">
		<title>Animal Shelter | Login</title>
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
						<li class= "current"><a href= "login.php">Sign In</a></li>
					</ul>
				</nav>
			</div>
		</header>

		<section id= "login">
			<div class="container">
				<form method = "post" action = "">
					<h1>Sign In</h1>
                    <font color = "white">Incorrect Username or Password</font>

					<div class="form-input">
						<input type="text" name = "username" placeholder="Username or Email"/>	
					</div>
					<div class="form-input">
						<input type="password" name = "pwd" placeholder="Password"/>
					</div>
					<input type="submit" name = "submit" class= "button_1" value = "LOGIN"/>

					<nav id= "create">
						<button type = "submit" class= "button_2"><a href= "create_account.php" style="color:white">No Account? Sign Up!</a></button>
					</nav>

					<nav id= "create">
						<button type = "submit" class= "button_2"><a href= "create_admin.php" style="color:white">Create Admin Account</a></button>
					</nav>
				</form>
			</div>	
		</section>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

<!--Taking login input, check database if user exists, set active user if user exists-->
<?php
	if(isset($_POST['submit']) && !empty($_POST['submit']))
	{
	// Variables
		$username = $_POST['username'];
		$email = $_POST['username'];
		$pwd = $_POST['pwd'];

	// Connect to database
		include('connection.php');

	// Check database if user exists
		$profile_result = mysqli_query($con, "SELECT PROFILE_ID FROM profile WHERE (Username = '$username' OR Email = '$email') AND Pwd = '$pwd'");
		$admin_result = mysqli_query($con, "SELECT ADMIN_ID FROM admin WHERE (Username = '$username' OR Email = '$email') AND Pwd = '$pwd'");
		if(mysqli_num_rows($profile_result) == 0 && mysqli_num_rows($admin_result) == 0)
			header('Location: login_again.php');
		
		else
		{
		// Set active user
			session_start();
		
		// If login was a successful login from a user, set active_user_id to user's PROFILE_ID
			if(mysqli_num_rows($profile_result) != 0)
			{
				$result = mysqli_query($con, "SELECT PROFILE_ID FROM profile WHERE Username = '$username' OR Email = '$email'");
				$row = $result->fetch_assoc();
				$_SESSION['active_user_id'] = $row['PROFILE_ID']; 
			}
		
		// If login was a successful login from a admin, set active_user_id to user's ADMIN_ID
			else
			{
				$result = mysqli_query($con, "SELECT ADMIN_ID FROM admin WHERE Username = '$username' OR Email = '$email'");
				$row = $result->fetch_assoc();
				$_SESSION['active_user_id'] = $row['ADMIN_ID']; 
			}
		
		// Disconnect from database
			mysqli_close($con);
		
		// Re-direct to home page
			if(mysqli_num_rows($profile_result) != 0)
				header('Location: user_home.php');
			else
				header('Location: admin_home.php');
		}
	}
?>

	</body>
</html>
