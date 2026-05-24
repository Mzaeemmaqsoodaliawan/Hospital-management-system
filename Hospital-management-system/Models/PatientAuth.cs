namespace Hospital_Management_System.Models
{
    /// <summary>
    /// Represents patient authentication credentials for login.
    /// </summary>
    public class PatientAuth
    {
        private string _username;
        private string _password;

        /// <summary>
        /// Gets or sets the patient's username.
        /// </summary>
        public string Username
        {
            get { return _username; }
            set { _username = value; }
        }

        /// <summary>
        /// Gets or sets the patient's password.
        /// </summary>
        public string Password
        {
            get { return _password; }
            set { _password = value; }
        }

        /// <summary>
        /// Initializes a new instance of the PatientAuth class with default values.
        /// </summary>
        public PatientAuth()
        {
            _username = string.Empty;
            _password = string.Empty;
        }

        /// <summary>
        /// Initializes a new instance of the PatientAuth class with specified username and password.
        /// </summary>
        /// <param name="username">The patient's username.</param>
        /// <param name="password">The patient's password.</param>
        public PatientAuth(string username, string password)
        {
            _username = username;
            _password = password;
        }
    }
}
