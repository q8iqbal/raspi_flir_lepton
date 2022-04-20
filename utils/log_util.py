import logging
import os
from dotenv import load_dotenv

def get_log_level():
    load_dotenv()
    debug_level = "DEBUG"
    if debug_level == "DEBUG":
        return logging.DEBUG
    elif debug_level == "INFO":
        return logging.INFO
    elif debug_level == "WARNING":
        return logging.WARNING
    elif debug_level == "ERROR":
        return logging.ERROR
    elif debug_level == "NOTSET":
        return logging.NOTSET
    else:
        return logging.CRITICAL   

# Create a custom logger
logger = logging.getLogger(__name__)

# Create handlers
c_handler = logging.StreamHandler()
f_handler = logging.FileHandler('logger.log')
c_handler.setLevel(get_log_level())
f_handler.setLevel(get_log_level())

# Create formatters and add it to handlers
c_format = logging.Formatter('%(name)s - %(levelname)s - %(message)s')
f_format = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
c_handler.setFormatter(c_format)
f_handler.setFormatter(f_format)

# Add handlers to the logger
logger.addHandler(c_handler)
logger.addHandler(f_handler)
