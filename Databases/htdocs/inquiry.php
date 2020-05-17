<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<meta name= "viewport" content="width=device-width">
		<meta name= "descriptions" content="User friendly online animal shelter">
		<meta name= "keywords" content="animal, shelter, animal shelter, dogs, cats, adoption, donation, pets">
		<meta name= "author" content="Donovan Almendariz, Jerry Olds">
		<title>Animal Shelter | Inquiry</title>
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

		<section id= "Create2">
			<div class="container">
                <div class="dark">
				<form method = "post" action = "">
					<h1>INQUIRY</h1>

					<div class="form-input">
						<input type="text" name = "inquiry" placeholder="Make your inquiry"/>	
                    </div>
                
                    <input type="submit" name="submit" class = "button_1" value = "SUBMIT"/>
                </form>
                </div>
			</div>	
		</section>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

<!--Insert inquiry in to databse-->
<?php
	if(isset($_POST['submit']) && !empty($_POST['submit']))
	{
    
    // Connect to database
		include('connection.php');
    
    // Variables
        session_start();
        $inquiry = $_POST['inquiry'];
        $profile_id = $_SESSION['active_user_id'];
        $animal_id = $_SESSION['animal_id'];
        $result = mysqli_query($con, "SELECT First_Name, Last_Name FROM profile WHERE PROFILE_ID = '$profile_id'");
        $result2 = mysqli_query($con, "SELECT Name FROM animal WHERE ANIMAL_ID = '$animal_id'");
        $row = $result->fetch_assoc();
        $row2 = $result2->fetch_assoc();
        $first_name = $row['First_Name'];
        $last_name = $row['Last_Name'];
        $animal_name = $row2['Name'];
    
    // Insert inquiry to database
        $sql = "INSERT INTO inquiries (PROFILE_ID, Inquiry_Date, ANIMAL_ID, First_Name, Last_Name, Animal_Name, Question)
                VALUES ('$profile_id', NOW(), '$animal_id', '$first_name', '$last_name', '$animal_name', '$inquiry')";

    // Insert inquiry to transactions
        $sql2 = "INSERT INTO transactions (Transaction_Date, Transaction_Type, PROFILE_ID, First_Name, Last_Name, ANIMAL_ID, Animal_Name)
                 VALUES (NOW(), 'Inquiry', '$profile_id', '$first_name', '$last_name', '$animal_id', '$animal_name')";
    
    // Unsuccessful entry
        if(!mysqli_query($con, $sql) || !mysqli_query($con, $sql2))
            header('Location: error.php');
            
    // Successful entry
        else
        {
        // Disconnect from database
            mysqli_close($con);
        // Re-direct to home  page
            header('Location: user_home.php');
        }
		
	}
?>

	</body>
</html>
