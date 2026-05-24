namespace Hospital_Management_System.Models
{
    /// <summary>
    /// Represents doctor authentication credentials for login.
    /// </summary>
    public class DoctorAuth
    {
        private string _username;
        private string _password;

        /// <summary>
        /// Gets or sets the doctor's username.
        /// </summary>
        public string Username
        {
            get { return _username; }
            set { _username = value; }
        }

        /// <summary>
        /// Gets or sets the doctor's password.
        /// </summary>
        public string Password
        {
            get { return _password; }
            set { _password = value; }
        }

        /// <summary>
        /// Initializes a new instance of the DoctorAuth class with default values.
        /// </summary>
        public DoctorAuth()
        {
            _username = string.Empty;
            _password = string.Empty;
        }

        /// <summary>
        /// Initializes a new instance of the DoctorAuth class with specified username and password.
        /// </summary>
        /// <param name="username">The doctor's username.</param>
        /// <param name="password">The doctor's password.</param>
        public DoctorAuth(string username, string password)
        {
            _username = username;
            _password = password;
        }
    }
}
